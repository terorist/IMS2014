#include "libsim/libsim.h"
#include <iostream>

int main() { 
  Store* store = new Store();
  store->Enter(2);
  store->Enter(3);
  store->Enter(8);
  store->Enter(10);
  store->Enter(1);
  store->Enter(5);
  store->Enter(7);
  std::cout << store->queue[0].pop() << std::endl;
}
