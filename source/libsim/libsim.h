#ifndef __LIBSIM_H__
#define __LIBSIM_H__

#include <map>
#include <limits>
#include "event.h"
#include "process.h"
#include "store.h"
#include "facility.h"

//namespace libsim {

  typedef std::multimap<float,Event*> Timeline;

  //Time stamps
  double TIME = 0;
  double TIME_END = std::numeric_limits<double>::max;

  // Calendar -- TODO udelat strukturu - timeline, vyjmuty prvek z fronty zarizeni
  Timeline calendar;
  
  /**
   * Initialize start time and end time
   */
  void init (double t0 = TIME, double t1 = TIME_END {
    TIME = t0;
    TIME_END = t1;
    return;
  }
  
  /**
   * Main loop of calendar/simulator
   */
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
