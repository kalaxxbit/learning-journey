
#include "clsPerson.h"

#include <iomanip>
#include <iostream>
#include <string>
/*







*/
using namespace std;

class clsEmoloyee : public clsPerson {
private:
  string _Title;
  string _Department;
  float _Salary = 0;

public:
  clsEmoloyee(short ID, string FirstName, string LastName, string Email,
              string PhoneNm, string Title, string Department, float Salary)
      : clsPerson(ID, FirstName, LastName, Email, PhoneNm) {
    _Department = Department;
    _Salary = Salary;
    _Title = Title;
  }

  string GetDepartment() { return _Department; }
  void SetDepartment(string Department) { _Department = Department; }
  float GetSalary() { return _Salary; }
  void SetSalary(float Salary) { _Salary = Salary; }
  string GetTitle() { return _Title; }
  void SetTitle(string Title) { _Title = Title; }
  void Print() {
    cout << "Info :" << endl;
    cout << "_________________________________" << endl;

    cout << left << setw(12) << "ID" << ": " << GetID() << endl;
    cout << left << setw(12) << "FirstName" << ": " << GetFirstName() << endl;
    cout << left << setw(12) << "LastName" << ": " << GetLastName() << endl;
    cout << left << setw(12) << "Full Name" << ": " << FullName() << endl;

    cout << left << setw(12) << "Email" << ": " << GetEmail() << endl;
    cout << left << setw(12) << "PhoneNm" << ": " << GetPhoneNm() << endl;

    cout << left << setw(12) << "Title" << ":" << _Title << endl;
    cout << left << setw(12) << "Department" << ":" << _Department << endl;
    cout << left << setw(12) << "Salary" << ":" << _Salary << endl;
    cout << left << setw(12) << "_________________________________" << endl;
  }
};