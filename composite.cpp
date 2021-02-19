#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// component
class Employee {

public:
  Employee() {}

  virtual void traverse() = 0;
};

// Leaf
class Engineer : public Employee {
  string name;
  int age;

public:
  Engineer(string name, int age) : name(name), age(age) {}

  void traverse() { cout << name << endl; }
};

// Composite
class Manager : public Employee {
  vector<Employee *> employees;
  string name;
  int age;

public:
  Manager(string name, int age) : name(name), age(age) {}
  void addEmployee(Employee *e) { employees.push_back(e); }

  void traverse() {
    for (int i = 0; i < employees.size(); ++i) {
      employees[i]->traverse();
    }
    cout << name << endl;
  }
  vector<Employee *> getEmployees() { return this->employees; }
};

int main() {
  Manager *alice = new Manager("Alice", 35);
  Manager *dave = new Manager("Dave", 35);
  Employee *bob = new Engineer("Bob", 35);
  Employee *amitai = new Engineer("Amitai", 35);
  alice->addEmployee(dave);
  alice->addEmployee(amitai);
  dave->addEmployee(alice);
  alice->traverse();
}