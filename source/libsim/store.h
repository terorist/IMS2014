#ifndef __STORE_H__
#define __STORE_H__

#include <map>
#include <queue>
#include "libsim.h"
#include "stat.h"

typedef /*std::map<int, */std::queue<Event*>/* >*/ Queue;

struct errorStoreLeave : std::exception {
  const char* what() const throw() {return "Error: leaving more than entered\n";}
};

class Store {
public:
  Store(const char* n, unsigned long size = 1) {
    capacity = size;
    entered = 0;
    name = n;
    statistic = new Stats(n);
    //queue[0] = new std::queue<Event*>;
  }
  
  void Enter(Event* proc, unsigned long reserve = 1/*, int priority = 0*/) {
    //Whole capacity is used - process to queue
    if (Full() || entered+reserve > capacity) { //TODO pokud se zabere vetsi kapacita, nemusi platit FIFO, muze byt nedefinovano
      queue/*[priority]*/.push(proc);
      statistic->EnterQueue(reserve);
      entered += reserve;
      return;
    }
    entered += reserve;
    statistic->EnterNonqueued(reserve);
    proc->Activate();
  }
  
  void Leave(unsigned long reserved = 1) {
    //Process in queue
    if (/*Full()*/!queue.empty()) {
      queue.front()->Activate();
      statistic->LeaveQueue(reserved);
      queue.pop();
      /*for (Queue::reverse_iterator it = queue.rbegin(); it != queue.rend(); ++it) {
        if (it->second->empty()) {
          continue;
        }
        it->second->front()->Activate();
        it->second->pop();
        break;
      }*/
      
    }
    unsigned long tmp = entered;
    entered -= reserved;
    if (tmp < entered) {
      throw new errorStoreLeave;
    }
  }
  
  bool Full() {
    return !(capacity>entered);
  }
  
  bool Empty() {
    return entered == 0;
  }
  
  void PrintStats() {
    statistic->PrintStats();
  }
  
  const char* name;
  
private:
  unsigned long capacity;
  unsigned long entered;
  Queue queue;
  Stats* statistic;
};

#endif // __STORE_H__
