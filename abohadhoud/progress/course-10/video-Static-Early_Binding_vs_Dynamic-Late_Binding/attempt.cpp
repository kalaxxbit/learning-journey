#include "../../../lib/MySmallLibrary.h"
#include <iostream>

using namespace std;

class clsPerson {

public:
  virtual void Print() { cout << "HI Im Person\n"; }
};

class clsEmployee : public clsPerson {
public:
  void Print() { cout << "HI Im  An Emp\n"; }
};

class clsStudent : public clsPerson {
public:
  void Print() { cout << "HI Im Student\n"; }
};
int main() {
  clsEmployee Emp;
  clsStudent Student;
  Emp.Print();
  Student.Print();
  clsPerson *Person1 = &Emp;
  clsPerson *Person2 = &Student;
  Person1->Print();
  Person2->Print();
  return 0;
}