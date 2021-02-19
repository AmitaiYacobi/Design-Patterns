#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Singelton {
  static Singelton *instance;
  Singelton() {}

public:
  static Singelton *getSingelton() {
    if (!instance) {
      instance = new Singelton();
      cout << "First instance" << endl;
      return instance;
    } else {
      cout << "There is already an instance" << endl;
      return instance;
    }
  }
};
Singelton *Singelton::instance = 0;
int main() {
  Singelton *s1 = Singelton::getSingelton();
  Singelton *s2 = Singelton::getSingelton();
  return 0;
}
