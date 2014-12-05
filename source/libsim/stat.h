#ifndef __STAT_H__
#define __STAT_H__

#include <iostream>
#include <queue>
#include "libsim.h"

class Stats {
public:
  Stats(const char* n) {
    name = n;
    max = 0;
    minWaitTime = -1.0;
    maxWaitTime = 0.0;
    avgWaitTime = 0.0;
    withoutQueue = 0;
    requests = 0;
  }
  
  void EnterNonqueued(unsigned long pocet) {
    requests += pocet;
    withoutQueue += pocet;
  }
  
  void EnterQueue(unsigned long pocet) {
    for (unsigned long i = 0; i < pocet; ++i) {
      times.push(TIME);
    }
    
    if (times.size() > max) {
      max = times.size();
    }
    
    requests += pocet;
  }
  
  void LeaveQueue(unsigned long pocet) {
    double currentWaitTime = 0.0;
    for (unsigned long i = 0; i < pocet; ++i) {
      currentWaitTime = TIME - times.front();
      avgWaitTime += currentWaitTime;
      times.pop();
      if (minWaitTime > currentWaitTime || minWaitTime < 0.0) {
        minWaitTime = currentWaitTime;
      }
      if (maxWaitTime < currentWaitTime) {
        maxWaitTime = currentWaitTime;
      }
    }
  }
  
  void PrintStats() {
    std::cout << "\n+-------------------------------------------------------+" <<
    "\n| Store: " << name <<
    "\n+-------------------------------------------------------+" <<
    "\n| Celkovy pocet pozadavku: " << requests <<
    "\n| Pocet pozadavku bez fronty: " << withoutQueue <<
    "\n| Aktualni delka fronty: " << times.size() <<
    "\n| Maximalni delka fronty: " << max <<
    "\n| Minimalni cas cekani: " << minWaitTime <<
    "\n| Maximalni cas cekani: " << maxWaitTime <<
    "\n| Prumerny cas cekani: " << avgWaitTime/(requests-withoutQueue) <<
    "\n+-------------------------------------------------------+\n\n";
  }
  
  unsigned long max; // maximalni delka fronty
  std::queue<double> times; // casy vstupu - current = times.size()
  unsigned long requests; //pocet pozadavku celkem ve fronte
  unsigned long withoutQueue;
  double minWaitTime;
  double maxWaitTime;
  double avgWaitTime;
  const char* name;
};

#endif // __STAT_H__
