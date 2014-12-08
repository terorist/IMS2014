#ifndef __EVENT_H__
#define __EVENT_H__

#include <map>
#include <string>
#include "libsim.h"

class Event {
public:
  virtual ~Event() {}
  virtual void Behavior() {
  }
  
  //Aktivace eventu za urcity cas
  void Activate(double t) {
    calendar.insert(std::make_pair(TIME+t, this));
  }
  
  //aktivace eventu v aktualnim case
  void Activate() {
    calendar.insert(std::make_pair(TIME, this));
  }
};

#endif // __EVENT_H__
