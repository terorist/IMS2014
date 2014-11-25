#include <iostream>
#include <map>

using namespace std;

int main() {
  //Test, zda se seradi prvky podle floatoveho klice - usetri to spoustu casu a namahy
  //pro stejne klice je jejich poradi nedefinovane, ale po spusteni 500x se to chova podle vkladani (nelze se na to ale spolehnout)
  multimap<float, char> timeline;

  timeline.insert(make_pair(3.998454, 'e'));
  timeline.insert(make_pair(4.5624, 'l'));
  timeline.insert(make_pair(9.2130, 'd'));
  timeline.insert(make_pair(5.96, ' '));
  timeline.insert(make_pair(6.46524, 'w'));
  timeline.insert(make_pair(2.387, 'H'));
  timeline.insert(make_pair(7.54682, 'o'));
  timeline.insert(make_pair(7.9856, 'r'));
  timeline.insert(make_pair(8.45682, 'l'));
  timeline.insert(make_pair(5.165123, 'o'));
  timeline.insert(make_pair(10.24654, '!'));
  timeline.insert(make_pair(10.24654, '?'));
  timeline.insert(make_pair(4.5624, 'l'));
  timeline.insert(make_pair(10.24654, '.'));

  multimap<float, char>::iterator pos;

  for(pos = timeline.begin(); pos != timeline.end(); ++pos) {
    cout << pos->second;
  }
  cout << endl;

  while (!timeline.empty()) {
    cout << timeline.begin()->second;
    timeline.erase(timeline.begin());
  }
  cout << endl;

  return 0;
}
