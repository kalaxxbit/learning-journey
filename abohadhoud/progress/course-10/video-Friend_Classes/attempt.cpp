#include <iostream>
#include <termios.h>

using namespace std;
class clsA {
private:
  int _Var1;

protected:
  int _Var3 = 3;

public:
  int Var2;
  clsA() {
    _Var1 = 10;
    Var2 = 20;
  }
  friend class clsB;
};
class clsB {
public:
  void display(clsA A1) {
    cout << endl << "The Value of Var3=" << A1._Var3;

    cout << endl << "The Value of Var1=" << A1._Var1;
    cout << endl << "The Value of Var2=" << A1.Var2;
  }
};
int main() {
  clsA A1;
  clsB B2;

  B2.display(A1);
  return 0;
}
