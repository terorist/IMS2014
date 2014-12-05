#ifndef __EVENT_H__
#define __EVENT_H__

#include <map>
#include <string>
#include "libsim.h"

class Event {
public:
  Event() {
  }
  ~Event() {
  }
  virtual void Behavior() {
  }
  void Activate(double t) {
    calendar.insert(std::make_pair(TIME+t, this));
  }
  void Activate() {
    calendar.insert(std::make_pair(TIME, this));
  }
};

#endif // __EVENT_H__
