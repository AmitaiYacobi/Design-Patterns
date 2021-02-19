#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// adaptee
class Sorter {
public:
  virtual void sort(int ints[], int size) = 0;
};

// kind of adaptee
class Quicksorter : public Sorter {
public:
  void sort(int ints[], int size) {
    qsort(ints, size, sizeof(int),
          [](const void *a, const void *b) { return (*(int *)a - *(int *)b); });
  }
};

class Task {
  virtual void doTask() = 0;
};

// the adapter - abstact adapter.
class SorterTask : public Task {
  Sorter *s; // the adaptee
  int size;
  int *ints;

public:
  SorterTask(Sorter *s, int array[], int size) {
    this->s = s;
    ints = array;
    this->size = size;
  }
  void doTask() {
    s->sort(ints, size);
    for (int i = 0; i < size; ++i) {
      cout << ints[i] << ' ';
    }
    cout << endl;
  }
};

int main() {
  int myInts[] = {3, 4, 6, 3, 2, 1, 0};
  int size = 7;
  Sorter *s = new Quicksorter();
  SorterTask task(s, myInts, size);
  task.doTask();
}