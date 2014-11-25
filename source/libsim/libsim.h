#ifndef __LIBSIM_H__
#define __LIBSIM_H__

#include <map>
#include "event.h"
#include "process.h"
#include "store.h"
#include "facility.h"

//namespace libsim {

  typedef std::multimap<float,Event*> Timeline;

  //Time stamps
  double TIME = 0;
  double TIME_END = DOUBLE_MAX;

  // Calendar
  Timeline calendar;
  
  void run() {
    Event* actual;
    while (!calendar.empty()) {
      //time break
      if (calendar.begin()->first > TIME_END) {
        break;
      }
      
      //set time to current event
      TIME = calendar.begin()->first;
      
      //get event
      actual = calendar.begin()->second;
      calendar.erase(calendar.begin());
      actual->behavior();
    }
  }
//}

#endif //__LIBSIM_H__
