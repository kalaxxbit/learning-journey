#include "../../../lib/MySmallLibrary.h"
#include <iostream>
#include <string>

using namespace std;
// Defin Person Class
class clsPerson {

private:
  string _FirstName;
  string _LastName;
  int _ID = 10;

public:
  string FullName() { return _FirstName + " " + _LastName; }

  int ID() { return _ID; }
  void setFirstName(string Name) { _FirstName = Name; }
  void setLastName(string Name) { _LastName = Name; }

  string FirstName() { return _FirstName; }
  string LastName() { return _FirstName; }
};
int main() {
  clsPerson Person1;
  Person1.setFirstName("Kalax");

  Person1.setLastName("xbit");
  cout << "ID: " << Person1.ID() << endl;
  cout << "First Name: " << Person1.FirstName() << endl;
  cout << "LastName: " << Person1.LastName() << endl;
  cout << "FullName: " << Person1.FullName() << endl;

  // string are class to
  // S1 is Object of class string
  string S1;
  return 0;
}
