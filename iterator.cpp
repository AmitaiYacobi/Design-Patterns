#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <class T> class MyContainer {
  T *arr;
  size_t size;
  size_t capacity;

public:
  MyContainer(size_t size) : size(size) { arr = new T[size]; }

  // copy constructor
  MyContainer(const MyContainer<T> &mc) {
    size = mc.size;
    arr = newT[size];
    for (int i = 0; i < size; ++i) {
      arr[i] = mc.arr[i];
    }
    capacity = size;
  }
  // mov constructor
  MyContainer(const MyContainer<T> &&mc) {
    size = mc.size;
    arr = mc.arr;
    capacity = size;
    mc.size = 0;
    mc.arr = nullptr;
  }

  // operator []
  const T &operator[](size_t index) {

    if (index > size) {
      throw "Out of bound";
    }
    return arr[index];
  }
  void push_back(T &t) {
    if (capacity >= size) {
      size *= 2;
      T *temp = new T[size];
      for (int i = 0; i < size; ++i) {
        temp[i] = this[i];
      }
      delete[] arr;
      arr = move(temp);
      arr[capacity] = t;
      capacity++;
    }
  }
  size_t size() { return capacity; }

  bool empty() { return capacity == 0; }

  virtual ~MyContainer() { delete arr; }

  class Iterator {

    T *it;

  public:
    Iterator(T *t) { this->it = it; }

    Iterator &operator++() {
      it++;
      return *this;
    }

    bool operator==(Iterator it) { return it == it.it; }

    bool operator<(Iterator it) { return it < it.it; }

    iterator &operator=(Iterator it) {
      it = it.it;
      return *this;
    }
    T &operator*() { return *this; }

    Iterator begin() { return (Iterator(&arr[0])); }
    Iterator end() { return (Iterator(&arr[capacity])); }
  };
};