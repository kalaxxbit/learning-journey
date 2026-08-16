#include "../../../lib/MySmallLibrary.h"
#include <iostream>
#include <string>

using namespace std;
// Defin Person Class
class clsPerson {

  int x = 0;

public:
  string FirstName;
  string LastName;
  string FullName() { return FirstName + " " + LastName; }
};
int main() {
  clsPerson Person1;

  Person1.FirstName = "Kalax";
  Person1.LastName = "xbit";
  cout << Person1.FullName() << endl;

  // string are class to
  // S1 is Object of class string
  string S1;
  return 0;
}
