#include "../../../lib/MySmallLibrary.h"
#include <functional>
#include <iostream>
#include <string>

using namespace std;
class clsPhoenix {
private:
  void ReturnFromFire() { cout << "Return From Fire" << endl; }
  void ReturnToFire() { cout << "Return To Fire" << endl; }

public:
  static int ReturnTimes;
  static int DieTimes;

  clsPhoenix() {
    ReturnFromFire();
    ReturnTimes++;
  }
  ~clsPhoenix() {
    ReturnToFire();
    DieTimes++;
  }
};
int clsPhoenix::ReturnTimes = 0;
int clsPhoenix::DieTimes = 0;
void Sky() {

  clsPhoenix Phoenix;
  clsPhoenix Phoenix2;
  clsPhoenix Phoenix3;
}

int main() {
  Sky();
  cout << clsPhoenix::ReturnTimes << endl;
  cout << clsPhoenix::DieTimes << endl;
}
