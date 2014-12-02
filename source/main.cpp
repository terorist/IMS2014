#include <iostream>
#include "libsim/libsim.h"

  #include <typeinfo>

Store* dojicky = new Store(5);
Store* rampa = new Store();
Store* kapacitaAuta = new Store(20);
Store* konvice = new Store(-1);
unsigned long vydojeno = 0;

class KravaMaDojicku : public Event {
public:
  KravaMaDojicku() {
    name="KravaMaDojicku";
  }
  void Behavior();
};

class KravaNaDojicku : public Event {
public:
  KravaNaDojicku() {
    name="KravaNaDojicku";
  }
  void Behavior();
};

class KravyTvorbaMleka : public Event {
public:
  KravyTvorbaMleka() {
    name="KravyTvorbaMleka";
  }
  void Behavior();
};

class KravaDodojila : public Event {
public:
  KravaDodojila() {
    name="KravaDodojila";
  }
  void Behavior();
};

void KravaMaDojicku::Behavior() {
  if (Random() < 0.1) {
    (new KravaDodojila)->Activate(Exponential(15.0));
  }
  else {
    (new KravaDodojila)->Activate(Exponential(8.0));
  }
  //delete this;
}

void KravaNaDojicku::Behavior() {
  dojicky->Enter(new KravaMaDojicku);
  //delete this;
}

void KravyTvorbaMleka::Behavior() {
  (new KravaNaDojicku)->Activate(Exponential(15.0 * 60.0));
  //delete this;
}

void KravaDodojila::Behavior() {
  konvice->Leave();
  ++vydojeno;
  dojicky->Leave();
  (new KravyTvorbaMleka)->Activate();
}

/*class AutoNaCeste : public Event {
  void Behavior();
};

class AutoNaRampe : public Event {
  void Behavior();
};

class CekaniNaKonvici : public Event {
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
  (new AutoNaRampe)->Activate(Uniform(1, 2));
}*/

int main() {
  konvice->Enter(new Event, -1);
  int kravy = 100;
  //int auta = 2;
  for (int i = 0; i < kravy; ++i) {
    (new KravyTvorbaMleka)->Activate();
  }
  /*for (int i = 0; i < auta; ++i) {
    (new AutoNaCeste)->Activate();
  }*/
  init(0, 200*60);
  run();
  std::cout << vydojeno << std::endl;

  while (!calendar.empty()) {
    std::cout << calendar.begin()->first << "\t" << calendar.begin()->second->name << std::endl;
    
    calendar.erase(calendar.begin());
  }
  std::cout << dojicky->queue[0]->size();
  return 0;
  
  /*for (int i = 0; i < 250; ++i)
    std::cout << Random() << std::endl;*/
}
