#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// prototype
class Shape {
public:
  virtual Shape *clone() const = 0;
  virtual void store() const = 0;
  virtual ~Shape(){};
};

// concretes prototypes: circlr, rectangle , triangle

class Circle : public Shape {
public:
  Shape *clone() const { return new Circle(); }
  void store() const { cout << "you'v chosev circle" << endl; }
};

class Triangle : public Shape {
public:
  Shape *clone() const { return new Triangle(); }
  void store() const { cout << "you'v chosen Triangle" << endl; }
};

class Rectangle : public Shape {
public:
  Shape *clone() const { return new Rectangle(); }
  void store() const { cout << "you'v chosen Rectangle" << endl; }
};

// Client which call the prototype's clone method.
class ShapesHolder {
  vector<Shape *> shapes;

public:
  ShapesHolder() { shapes = {new Circle(), new Rectangle(), new Triangle()}; }
  Shape *makeShape(int choice) { return shapes[choice]->clone(); }
  ~ShapesHolder() {}
};

int main() {
  ShapesHolder *holder = new ShapesHolder();
  int choice;
  cin >> choice;
  Shape *s = holder->makeShape(choice);
  s->store();
}