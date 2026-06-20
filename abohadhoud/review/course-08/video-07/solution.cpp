#include <iostream>
#include <string>
using namespace std;
// Problem #2
short ReadYear() {
  short Year = 0;
  cout << "\nPlease enter a year to check ? ";
  cin >> Year;
  return Year;
}
// Problem #
//
//
short ReadMonth() {
  short Month = 0;
  cout << "\nPlease enter a Month to check ? ";
  cin >> Month;
  return Month;
}
// Problem #7
short ReadDay() {
  short Day = 0;
  cout << "\nPlease enter a Day to check ? ";
  cin >> Day;
  return Day;
}
short DayOfWeekOrder(short Day, short Month, short Year) {
  short a, y, m;
  Please enter a Day to check ? 12 Date
                              : 12 / 8 / 2023 Day Order : 6 Day Name : Sat
}
a = (14 - Month) / 12;
y = Year - a;
m = Month + (12 * a) - 2;
// Gregorian:
// 0:sun, 1:Mon, 2:Tue...etc.
return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
11 string DayShortName(short DayOfWeekOrder) {
  string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
}
return arrDayNames[DayOfWeekOrder];
int main() {
  // Problem #7
  short Year = ReadYear();
  short Month = ReadMonth();
  short Day = ReadDay();
  short DayOrder = DayOfWeekOrder(Day, Month, Year);
  cout << "\n\nDate
      : " << Day << " /
        " << Month << " /
        " << Year <<
        endl;
  cout << "Day Order
      : " << DayOrder << endl;
        cout
       << "Day Name
      : " << DayShortName(DayOrder) << endl;
}
system("pause>0");
return 0;