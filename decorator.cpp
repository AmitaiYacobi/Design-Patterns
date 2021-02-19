#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// component
class Food {

public:
  virtual int getPrice() = 0;
};

// Decorator
class Decorator : public Food {
  Food *food;

public:
  Decorator(Food *f) : food(f) {}
  int getPrice() { return food->getPrice(); }
};

// concrete component
class Pizza : public Food {

public:
  int getPrice() { return 50; }
};

// concrete decorators
class Olives : public Decorator {
public:
  Olives(Food *d) : Decorator(d) {}
  int getPrice() { return 5 + Decorator::getPrice(); }
};

class Onions : public Decorator {
public:
  Onions(Food *d) : Decorator(d) {}
  int getPrice() { return 4 + Decorator::getPrice(); }
};

class mushrooms : public Decorator {
public:
  mushrooms(Food *d) : Decorator(d) {}
  int getPrice() { return 7 + Decorator::getPrice(); }
};

int main() {
  Food *pizza1 = new mushrooms(new Olives(new Pizza()));
  int price1 = pizza1->getPrice();
  cout << price1 << endl;
}