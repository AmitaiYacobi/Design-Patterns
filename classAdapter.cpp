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
class Quicksorter : Sorter {
public:
  void sort(int ints[], int size) {
    qsort(ints, size, sizeof(int),
          [](const void *a, const void *b) { return (*(int *)a - *(int *)b); });
  }
};

// target
class Task {
public:
  virtual void doTask() = 0;
};

// adapter
class QuickSorterTask : public Quicksorter, public Task {

  int size;
  int *ints;

public:
  QuickSorterTask(int array[], int size) {
    ints = array;
    this->size = size;
  }
  void doTask() {
    Quicksorter::sort(ints, size);
    for (int i = 0; i < size; ++i) {
      cout << ints[i] << ' ';
    }
    cout << endl;
  }
};

int main() {
  int myInts[] = {3, 4, 6, 3, 2, 1, 0};
  int size = 7;
  Task *task = new QuickSorterTask(myInts, size);
  task->doTask();
}