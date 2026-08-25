// #include "../../../lib/MySmallLibrary.h"
#include <iostream>
#include <string>

using namespace std;
// Defin Person Class
class clsA {
private:
  int _Var1;
  void _Func1() { cout << "FUnc 1"; }

protected:
  int Var2;
  void Func2() { cout << "FUnc 1"; }

public:
  int Var3;
  void Func3() { cout << "FUnc 1"; }
};
class clsB : protected clsA {
public:
  short Func4() {
    clsA::Func2();
    return 4;
  }
};

class clsC : public clsB {
public:
  void Func4() { clsB::Func3(); }
};

int main() {

  clsB B1;
  clsC C;

  return 0;
}
