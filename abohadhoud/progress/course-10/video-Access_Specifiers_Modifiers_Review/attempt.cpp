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
  int _Var2;
  void _Func2() { cout << "FUnc 1"; }

public:
  int _Var3;
  void _Func3() { cout << "FUnc 1"; }
};
class clsB : public clsA {
public:
  void Func1() { clsA::_Func2(); }
};
int main() {
  clsB B;

  return 0;
}
