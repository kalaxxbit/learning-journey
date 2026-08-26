#include "../../../lib/MySmallLibrary.h"
#include <iostream>

using namespace std;

class clsPerson {
public:
  string FullName = "KAlAx-xbit";
};

class clsEmployee : public clsPerson {
public:
  string Title = "CEO";
};
int main() {
  clsEmployee E;
  cout << E.FullName << endl;
  // up casting
  clsPerson *Person = &E;
  cout << Person->FullName;

  // down Casting
  // You Cant Use It Btw (:
  /*clsPerson Person2;
  cout << Person2.FullName << endl;
  clsEmployee *Employee = &Person2;*/
  return 0;
}
