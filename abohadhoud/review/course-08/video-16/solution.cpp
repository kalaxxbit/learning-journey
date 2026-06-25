#include <iostream>
#include <string>
using namespace std;
// Problem #11
struct {};
sDate shortshortshortYear;
Month;
Day;
// Problem #3
bool IsLeapYear(short Year) {
  return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year) {
  if (Month < 1 || Month > 12)
    return 0;
  Write a program to read Date and make function to Increase by one Day Please
      enter a Day to check
      ? 31 Please enter a Month to check
      ? 12 Please enter a year to check
            ? 2023 Date after adding one Day is
            : 1 / 1 / 2024 int NumberOfDays[12] = {31, 28, 31, 30, 31, 30,
                                                   31, 31, 30, 31, 30, 31};
  return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
// Problem #15
bool IsLastDayInMonth(sDate Date) {
  return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month) { return (Month == 12); }
33
    // Problem #16
    sDate IncreaseDateByOneDay(sDate Date) {
  if (IsLastDayInMonth(Date)) {
    if (IsLastMonthInYear(Date.Month)) {
      Date.Month = 1;
      Date.Day = 1;
      Date.Year++;
    } else {
      Date.Day = 1;
      Date.Month++;
    }
  } else {
    Date.Day++;
  }
  return Date;
}
// Problem #7
short ReadDay() {
  short Day = 0;
  cout << "\nPlease enter a Day to check ? ";
  cin >> Day;
}
return Day;
// Problem #5
short ReadMonth() {
  short Month = 0;
  cout << "\nPlease enter a Month to check ? ";
  cin >> Month;
  return Month;
}
// Problem #2
short ReadYear() { short Year = 0; }
cout << "\nPlease enter a year to check ? ";
cin >> Year;
return Year;
34
    // Problem #12
    sDate ReadFullDate() {
  sDate Date;
  Date.Day = ReadDay();
  Date.Month = ReadMonth();
  Date.Year = ReadYear();
  return Date;
}
int main() {
  // Problem #16
  sDate Date = ReadFullDate();
  Date = IncreaseDateByOneDay(Date);
}
cout << "\nDate after adding one Day is : " << Date.Day << "/" << Date.Month
     << "/" << Date.Year;
system("pause>0");
return 0;