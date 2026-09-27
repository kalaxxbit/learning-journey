
#include <cstddef>
#include <ctime>
#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;
// Passing Objects to Functions (ByRef/ByVal)Functions(ByRef / ByVal)
// ProgrammingAdivces.com
// Mohammed Abu-Hadhoud

class clsA {
public:
  int x = 50;
  void Print() { cout << "The value of x=" << x << endl; }
};
// object sent by value, any updated will not b reflected
//  on the original object
void Fun1(clsA A1) { A1.x = 100; }

void Fun(clsA &A1) { A1.x = 200; }
int main() {
  clsA A;
  A.Print();
  Fun1(A);
  A.Print();
  Fun(A);
  A.Print();
  return 0;
}
