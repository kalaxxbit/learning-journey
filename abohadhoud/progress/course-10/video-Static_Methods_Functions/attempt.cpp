#include "../../../lib/MySmallLibrary.h"
#include <functional>
#include <iostream>
#include <string>

using namespace std;
class clsA {
private:
  int _Function() { return B; }
  int A = 10;

public:
  static int B;
  static int FunctionB() { return B; }
  int FunctionA() { return A; }
};
int clsA::B = 20;
int main() {
  clsA A;
  cout << clsA::FunctionB() << endl;
  cout << A.FunctionA();
}
