#include <iostream>
#include "libsim/libsim.h"

Store* dojicky = new Store("Dojicky", 3);
Store* rampa = new Store("Rampa");
Store* kapacitaAuta = new Store("KapacitaAuta", 20);
Store* konvice = new Store("Konvice");
unsigned long vydojeno = 0;
unsigned long odvezeno = 0;

class KravaMaDojicku : public Event {
public:
  void Behavior();
};

class KravaNaDojicku : public Event {
public:
  void Behavior();
};

class KravyTvorbaMleka : public Event {
public:
  void Behavior();
};

class KravaDodojila : public Event {
public:
  void Behavior();
};

void KravaMaDojicku::Behavior() {
  if (Random() < 0.1) {
    (new KravaDodojila)->Activate(Exponential(15.0));
  }
  else {
    (new KravaDodojila)->Activate(Exponential(8.0));
  }
}

void KravaNaDojicku::Behavior() {
  dojicky->Enter(new KravaMaDojicku);
}

void KravyTvorbaMleka::Behavior() {
  (new KravaNaDojicku)->Activate(Exponential(15.0 * 60.0));
}

void KravaDodojila::Behavior() {
  if (konvice->Full()) {
    konvice->Leave();
  }
  ++vydojeno;
  dojicky->Leave();
  (new KravyTvorbaMleka)->Activate();
}

class AutoNaCeste : public Event {
  void Behavior();
};

class AutoNaRampe : public Event {
  void Behavior();
};

class CekaniNaKonvici : public Event {
  void Behavior();
};

class NakladaniKonvice : public Event {
  void Behavior();
};

void AutoNaCeste::Behavior() {
  rampa->Enter(new AutoNaRampe);
}

void AutoNaRampe::Behavior() {
  if (kapacitaAuta->Full()) {
    rampa->Leave();
    kapacitaAuta->Leave(20);
    (new AutoNaCeste)->Activate(60);
  }
  else {
    konvice->Enter(new CekaniNaKonvici);
  }
}

void CekaniNaKonvici::Behavior() {
  if (odvezeno < vydojeno) {
    ++odvezeno;
    kapacitaAuta->Enter(new NakladaniKonvice);
  }
  else {
    //konvice->Enter(this);
    konvice->Enter(new CekaniNaKonvici);
  }
}

void NakladaniKonvice::Behavior() {
  (new AutoNaRampe)->Activate(Uniform(1, 2));
}

int main() {
  int kravy = 100;
  int auta = 2;
  for (int i = 0; i < kravy; ++i) {
    (new KravyTvorbaMleka)->Activate();
  }
  for (int i = 0; i < auta; ++i) {
    (new AutoNaCeste)->Activate();
  }
  init(0, 200*60);
  run();

  //Tisk statistik
  rampa->PrintStats();
  dojicky->PrintStats();

  //Uvolneni pameti
  endSimulation();
  delete rampa;
  delete dojicky;
  delete konvice;
  delete kapacitaAuta;

  return 0;
}
