#ifndef __STORE_H__
#define __STORE_H__

#include <map>
#include <queue>
#include "libsim.h"

class Store {
public:
  Store(int size = 1) {
    capacity = size;
    entered = 0;
  }
  void Enter(/*Process*/ int proc, int priority = 0) {
    if (IsFull) {
//      proc->Passivate();
      queue[priority].push(proc); //TODO queue
    }
  }
  void Leave();
  
  int IsFull() {
    return !(capacity>entered);
  }
protected:
  int capacity;
  int entered;
  //TODO
public:
  std::map<int, std::queue</*Process*/int> > queue;
};

#endif // __STORE_H__
