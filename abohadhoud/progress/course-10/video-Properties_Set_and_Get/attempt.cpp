#include "../../../lib/MySmallLibrary.h"
#include <iostream>
#include <string>

using namespace std;
// Defin Person Class
class clsPerson {

private:
  string _FirstName;
  string _LastName;

public:
  void setFirstName(string Name) { _FirstName = Name; }
  void setLastName(string Name) { _LastName = Name; }

  string FirstName() { return _FirstName; }
  string LastName() { return _LastName; }
  string FullName() { return FirstName() + " " + LastName(); }
};

int main() {
  clsPerson Person1;

  Person1.setFirstName("Kalax");

  Person1.setLastName("xbit");

  cout << Person1.FullName() << endl;

  return 0;
}
