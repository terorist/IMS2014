#include "libsim.h"

typedef struct Stat {
  int max; // maximalni delka fronty
  query<double> times; // casy vstupu - current = times.size()
  int requests; //pocet pozadavku
} Stat;

class Stats {
  Stats() {
    //map[name]
  }
  Enter(name);
  Leave(name);
}
