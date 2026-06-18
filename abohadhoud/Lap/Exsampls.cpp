#include "../lib/MySmallLibrary.h"
#include <iomanip>
#include <vector>
using namespace std;

// DANGER
// testing area
//  keep out

// Declaration Vs Definition
void A();
void B() {

  cout << "IM B" << endl;
  A();
}
void A() {
  cout << "IM A" << endl;
  B();
}
// DefAult Parameters
int MySum(int a, int b, int c = 0, int d = 0) { return (a + b + c + d); }

void PrintNumbers(int N, int M) {
  if (N <= M) {
    cout << N << endl;
  }
  PrintNumbers(N + 1, M);
  // 1 + 1 = 2 | 2 + 1 = 3 | 3 + 1 = 4 ;
}

void MyFunctionStatic() {
  // Function ءاهتناب Static عم ريغتملا ةايح يهتنت لا
  //  هئاعدتسلا ةقباسلا ةميقلا ىلع ظفاحي
  static int Number = 1; // 2
}

void Swap(int &a, int &b) {
  int Temp = a;
  a = b;
  b = Temp;
}
void SwapVectorRandom(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    Swap(v.at(i), v.at(RandomFromTo(0, v.size() - 1)));
  }
}
bool Bah(string &S, char &I) {
  if (S.length() > 0) {
    I = S[S.length() - 1];
    S.pop_back();
    return 1;
  }
  return 0;
}
int main(int argc, char *argv[]) {
  string S = "987654321";
  char I = 0;
  while (Bah(S, I)) {
    cout << I << endl;
  }
  return 0;
}
