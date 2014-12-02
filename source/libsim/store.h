class Store {
public:
  Store(int size = 1) {
    capacity = size;
    seized = 0;
  }
  void seize(Process* proc, int priority = 0);
  void release();
  bool seized() {
  
  }
protected:
  int capacity;
  int seized;
  //TODO
  fronta queue;
};
