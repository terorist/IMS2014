#ifndef __LIBSIM_H__
#define __LIBSIM_H__

#include <map>
#include <climits>
#include "gen.h"

class Event;
//namespace libsim {

  typedef std::multimap<float,Event*> Timeline;

  //Time stamps
  double TIME = 0;
  double TIME_END = 10^256;//std::numeric_limits<double>::max;

  // Calendar
  Timeline calendar;
  
  #include "event.h"
  #include "store.h"

  /**
   * Initialize start time and end time
   */
  void init (double t0 = TIME, double t1 = TIME_END) {
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
      actual->Behavior();
      delete actual;
    }
  }
  
  void endSimulation() {
    Event* actual;
    //vyprazdneni kalendare
    while (!calendar.empty()) {
      actual = calendar.begin()->second;
      calendar.erase(calendar.begin());
      delete actual;
    }
  }
//}

#endif //__LIBSIM_H__
