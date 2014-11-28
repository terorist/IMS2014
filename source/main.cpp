#include <iostream>
#include "libsim/libsim.h"

class Gen : public Event {
  int count;
public:
  Gen() {
    count = 0;
  }
  void Behavior() {
    std::cout << "Event" << TIME << std::endl;
    if (this->count < 5) {
      Activate(5.0);
    }
    ++count;
  }
};

int main() {
  (new Gen)->Activate();
  run();
  return 0;
}
