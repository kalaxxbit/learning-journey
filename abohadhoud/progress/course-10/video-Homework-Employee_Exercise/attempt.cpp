#include <iomanip>
#include <iostream>
#include <string>
/*







*/
using namespace std;
class clsEmployee {
private:
  short _ID;
  string _FirstName;
  string _LastName;
  string _Title;
  string _Email;
  string _PhoneNm;
  string _Department;
  int _Salary;

  bool _SendEmailLogic() { return true; }
  bool _SendSMSLogic() { return true; }

public:
  clsEmployee(short ID, string FirstName, string LastName, string Title,
              string Email, string PhoneNm, int Salary, string Department) {
    _ID = ID;
    _FirstName = FirstName;
    _LastName = LastName;
    _Title = Title;
    _Email = Email;
    _PhoneNm = PhoneNm;
    _Salary = Salary;
    _Department = Department;
  }
  short GetID() { return _ID; }
  string GetFirstName() { return _FirstName; }
  string GetLastName() { return _LastName; }
  string GetEmail() { return _Email; }
  string GetPhoneNm() { return _PhoneNm; }
  string GetTitle() { return _Title; }

  int GetSalary() { return _Salary; }
  string GetDepartment() { return _Department; }

  void SetTitle(string Text) { _Title = Text; }
  void SetFirstName(string Text) { _FirstName = Text; }
  void SetLastName(string Text) { _LastName = Text; }
  void SetEmail(string Text) { _Email = Text; }
  void SetPhoneNm(string Text) { _PhoneNm = Text; }
  void SetSalary(int Salary) { _Salary = Salary; }
  void SetDepartment(string Text) { _Department = Text; }

  string FullName() { return _FirstName + " " + _LastName; }
  void Print() {
    cout << "Info :" << endl;
    cout << "_________________________________" << endl;

    cout << left << setw(12) << "ID" << ": " << _ID << endl;
    cout << left << setw(12) << "FirstName" << ": " << _FirstName << endl;
    cout << left << setw(12) << "LastName" << ": " << _LastName << endl;
    cout << left << setw(12) << "Full Name" << ": " << FullName() << endl;
    cout << left << setw(12) << "Title" << ": " << _Title << endl;

    cout << left << setw(12) << "Email" << ": " << _Email << endl;
    cout << left << setw(12) << "PhoneNm" << ": " << _PhoneNm << endl;
    cout << left << setw(12) << "Salary" << ": " << _Salary << endl;
    cout << left << setw(12) << "Department" << ": " << _Department << endl;

    cout << "_________________________________" << endl;
  }
  void SendEmail(string Subject, string MsgBody) {
    if (_SendEmailLogic()) {

      cout << "The Following Message sent successfully To Email : "
           << GetEmail() << endl;
      cout << "Subject : " << Subject << endl;
      cout << "Message : " << MsgBody << endl;
    } else {
      cout << "Faild To Send This Message " << endl;
    }
  }
  void SendSMS(string MsgBody) {
    if (_SendSMSLogic()) {

      cout << "The Following Message sent successfully To Phone Number : "
           << GetPhoneNm() << endl;

      cout << "Message : " << MsgBody << endl;
    } else {
      cout << "Faild To Send This Message " << endl;
    }
  }
};
int main() {
  clsEmployee Employee1(10, "kalax", "xbit", "C++ Dev", "kal@xxbit.com",
                        "+0000912345678", 100000, "Devlopmnt");

  Employee1.Print();
  Employee1.SendEmail("hi", "How are you ?");
  Employee1.SendSMS("How are you ?");

  return 0;
}
