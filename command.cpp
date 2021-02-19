#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Command interface
class Command {
public:
  virtual void execute() = 0;
};

// Receiver
class Receiver {
public:
  void printHello() { cout << "Hello World" << endl; }
  void printGoodbye() { cout << "Goodbye World" << endl; }
};
// concrete commands
class PrintHello : public Command {
  Receiver *receiver;

public:
  PrintHello(Receiver *c) : receiver(c) {}
  void execute() { receiver->printHello(); }
};

class PrintGoodbye : public Command {
  Receiver *receiver;

public:
  PrintGoodbye(Receiver *c) : receiver(c) {}
  void execute() { receiver->printGoodbye(); }
};

// invoker
class Invoker {
  Command *command;

public:
  void setCommand(Command *c) { command = c; }
  void buttonPressed() { command->execute(); }
};

int main() {
  Receiver *r = new Receiver();           // contains the different actions
  PrintHello *pHello = new PrintHello(r); // concrete command
  PrintGoodbye *pGoodbye = new PrintGoodbye(r); // concrete command
  Invoker *i = new Invoker();
  // all of the actions are executed through the invoker
  i->setCommand(pHello);
  i->buttonPressed();
  i->setCommand(pGoodbye);
  i->buttonPressed();
}