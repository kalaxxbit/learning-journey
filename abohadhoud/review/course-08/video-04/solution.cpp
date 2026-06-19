#include <iostream>

using namespace std;
bool isLeapYear(short Year) {

  return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInYear(short Year) { return isLeapYear(Year) ? 366 : 365; }
short NumberOfHoursInYear(short Year) { return NumberOfDaysInYear(Year) * 24; }
short NumberOfMinutesInYear(short Year) {
  return NumberOfHoursInYear(Year) * 60;
}
short NumberOfSecondsInYear(short Year) {
  return NumberOfMinutesInYear(Year) * 60;
}

short ReadYear() {
  short Year = 0;
  cout << "enter year: ";
  cin >> Year;
  return Year;
}
int main() {
  short Year = ReadYear();
  cout << "Number of Days in Year [" << Year << "] is "
       << NumberOfDaysInYear(Year) << endl;

  cout << "Number of Hours in Year [" << Year << "] is "
       << NumberOfHoursInYear(Year) << endl;

  cout << "Number of Minutes in Year [" << Year << "] is "
       << NumberOfMinutesInYear(Year) << endl;

  cout << "Number of Seconds in Year [" << Year << "] is "
       << NumberOfSecondsInYear(Year) << endl;
  return 0;
}
