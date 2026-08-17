
#include <cstddef>
#include <ctime>
#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;
// Defin Person Class
class clsPerson {

private:
  int _GetMyID() { return (int)time(NULL); }
  string _FirstName = "kalax";
  string _LastName = "xbit";
  int _ID = _GetMyID();

public:
  string FullName() { return _FirstName + " " + _LastName; }

  int ID() { return _ID; }
  void setFirstName(string Name) { _FirstName = Name; }
  void setLastName(string Name) { _LastName = Name; }

  string FirstName() { return _FirstName; }
  string LastName() { return _FirstName; }
};
void PrintPersonInfo(clsPerson Person) {
  cout << "ID: " << Person.ID() << endl;
  cout << "First Name: " << Person.FirstName() << endl;
  cout << "LastName: " << Person.LastName() << endl;
  cout << "FullName: " << Person.FullName() << endl;
}
int main() {

  clsPerson Person1;
  // A wait time to genrate deffinres IDs
  sleep(1);
  clsPerson Person2;
  Person1.setFirstName("Kalax");
  Person1.setLastName("xbit");

  Person2.setFirstName("kali");
  Person2.setLastName("xbit");

  PrintPersonInfo(Person1);
  PrintPersonInfo(Person2);
  // string are class to
  // S1 is Object of class string
  string S1;
  return 0;
}
