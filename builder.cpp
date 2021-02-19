#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Wheel {
public:
  int size;
};

class Engine {
public:
  int horsepower;
};

class Body {
public:
  string shape;
};

// Final product (we are gonna build this product).
class Car {
public:
  Wheel *wheels[4];
  Engine *engine;
  Body *body;
  void specifications() {
    cout << "body:" << body->shape << endl;
    cout << "engine horsepower:" << engine->horsepower << endl;
    cout << "tire size:" << wheels[0]->size << endl;
  }
};

// Builder- the object that build the car

class Builder {
public:
  virtual Wheel *getWheel() = 0;
  virtual Engine *getEngine() = 0;
  virtual Body *getBody() = 0;
};

// Director - the object the resposible for how to use the builder
class Director {
  Builder *builder;

public:
  void setBuilder(Builder *builder) { this->builder = builder; }

  Car *getCar() {
    Car *car = new Car();

    car->body = builder->getBody();

    car->engine = builder->getEngine();

    car->wheels[0] = builder->getWheel();
    car->wheels[1] = builder->getWheel();
    car->wheels[2] = builder->getWheel();
    car->wheels[3] = builder->getWheel();

    return car;
  }
};

// concrete builders
/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder {
public:
  Wheel *getWheel() {
    Wheel *wheel = new Wheel();
    wheel->size = 22;
    return wheel;
  }

  Engine *getEngine() {
    Engine *engine = new Engine();
    engine->horsepower = 400;
    return engine;
  }

  Body *getBody() {
    Body *body = new Body();
    body->shape = "SUV";
    return body;
  }
};

/* Concrete builder for Nissan family cars */
class NissanBuilder : public Builder {
public:
  Wheel *getWheel() {
    Wheel *wheel = new Wheel();
    wheel->size = 16;
    return wheel;
  }

  Engine *getEngine() {
    Engine *engine = new Engine();
    engine->horsepower = 85;
    return engine;
  }

  Body *getBody() {
    Body *body = new Body();
    body->shape = "hatchback";
    return body;
  }
};

int main() {
  Car *car; // Final product

  /* A director who controls the process */
  Director director;

  /* Concrete builders */
  JeepBuilder jeepBuilder;
  NissanBuilder nissanBuilder;

  /* Build a Jeep */
  std::cout << "Jeep" << std::endl;
  director.setBuilder(&jeepBuilder); // using JeepBuilder instance
  car = director.getCar();
  car->specifications();

  std::cout << std::endl;

  /* Build a Nissan */
  std::cout << "Nissan" << std::endl;
  director.setBuilder(&nissanBuilder); // using NissanBuilder instance
  car = director.getCar();
  car->specifications();

  return 0;
}
