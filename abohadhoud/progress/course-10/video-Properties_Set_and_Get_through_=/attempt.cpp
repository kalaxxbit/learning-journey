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

  string GetFirstName() { return _FirstName; }
  string GetLastName() { return _LastName; }
  __declspec(property(get = GetLastName, put = setLastName)) string LastName;
  __declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;
};
int main() {
  clsPerson Person1;
  Person1.LastName = "xbit";

  Person1.FirstName = "Kalax";
  cout << Person1.LastName << endl;
  cout << Person1.FirstName << endl;

  // string are class to
  // S1 is Object of class string
  string S1;
  return 0;
}
