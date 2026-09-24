#include <iomanip>
#include <iostream>
#include <string>
/*







*/
using namespace std;

class clsEmoloyee {

public:
  int ID;
  string Name;
  float Salary = 0;

  clsEmoloyee(int ID, string Name, float Salary) {
    this->ID = ID;
    this->Name = Name;
    this->Salary = Salary;
  }
  static void Func1(clsEmoloyee Employee) { Employee.Print(); }
  void Func2() { Func1(*this); }
  void Print() { cout << " " << ID << " " << Name << " " << Salary; }
};
int main() {

  clsEmoloyee Employee1(10, "kalax", 5000);
  // Employee1.Print();
  Employee1.Func2();

  return 0;
}