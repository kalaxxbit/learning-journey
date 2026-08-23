#include <iomanip>
#include <iostream>
#include <string>
/*







*/
using namespace std;
class clsPerson {
private:
  short _ID;
  string _FirstName;
  string _LastName;
  string _Email;
  string _PhoneNm;
  bool _SendEmailLogic() { return true; }
  bool _SendSMSLogic() { return true; }

public:
  clsPerson(short ID, string FirstName, string LastName, string Email,
            string PhoneNm) {
    _ID = ID;
    _FirstName = FirstName;
    _LastName = LastName;
    _Email = Email;
    _PhoneNm = PhoneNm;
  }
  short GetID() { return _ID; }
  string GetFirstName() { return _FirstName; }
  string GetLastName() { return _LastName; }
  string GetEmail() { return _Email; }
  string GetPhoneNm() { return _PhoneNm; }

  void SetFirstName(string Text) { _FirstName = Text; }
  void SetLastName(string Text) { _LastName = Text; }
  void SetEmail(string Text) { _Email = Text; }
  void SetPhoneNm(string Text) { _PhoneNm = Text; }
  string FullName() { return _FirstName + " " + _LastName; }
  void Print() {
    cout << "Info :" << endl;
    cout << "_________________________________" << endl;

    cout << left << setw(12) << "ID" << ": " << _ID << endl;
    cout << left << setw(12) << "FirstName" << ": " << _FirstName << endl;
    cout << left << setw(12) << "LastName" << ": " << _LastName << endl;
    cout << left << setw(12) << "Full Name" << ": " << FullName() << endl;

    cout << left << setw(12) << "Email" << ": " << _Email << endl;
    cout << left << setw(12) << "PhoneNm" << ": " << _PhoneNm << endl;

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
int main() {
  clsEmoloyee Employee1(10, "kalax", "xbit", "kal@xxbit.com", "+0000912345678",
                        "Dev", "Programing", 5000);
  Employee1.Print();
  return 0;
}