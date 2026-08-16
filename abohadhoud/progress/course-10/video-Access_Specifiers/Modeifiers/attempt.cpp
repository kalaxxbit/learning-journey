// #include "../../../lib/MySmallLibrary.h"
#include <iostream>
#include <string>

using namespace std;
// Defin Person Class
class clsPerson {
private:
  int Variable1 = 5;
  int Function1() { return 40; }

protected:
  int Variable2 = 100;
  int Function2() { return 50; }

public:
  string FirstName;
  string LastName;
  string FullName() { return FirstName + " " + LastName; }
  float Function3() { return Function1() * Variable1 * Variable2; }
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
