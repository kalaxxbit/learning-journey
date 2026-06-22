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
  // if year is divisible by 4 AND not
  divisible by 100
      // OR if year is divisible by 400
      // then it is a leap year
      Write a program to read how many days to add to it,
      print the results on screen Please enter a Day to check
      ? 14 Please enter a Month to check
      ? 8 Please enter a year to check
      ? 2023 How many days to add
      ? 2500 return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
// Problem #6
short NumberOfDaysInAMonth(short Month, short Year) {
  if (Month < 1 || Month > 12)
    return 0;
  Date after adding[2500] days is : 18 / 6 / 2030
}
int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
// Problem #10
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
  short TotalDays = 0;
}
for (int i = 1; i <= Month - 1; i++) {
  TotalDays += NumberOfDaysInAMonth(i, Year);
}
TotalDays += Day;
return TotalDays;
24
    // Problem #12
    sDate DateAddDays(short Days, sDate Date) {
  short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(
                                   Date.Day, Date.Month, Date.Year);
  short MonthDays = 0;
  Date.Month = 1;
  while (true) {
    MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (RemainingDays > MonthDays) {
      RemainingDays -= MonthDays;
      Date.Month++;
      if (Date.Month > 12) {
        Date.Month = 1;
        Date.Year++;
      }
    } else {
      Date.Day = RemainingDays;
      break;
    }
  }
  return Date;
}
// Problem #7
short ReadDay() { short Day = 0; }
cout << "\nPlease enter a Day to check ? ";
cin >> Day;
return Day;
// Problem #5
short ReadMonth() {
  short Month = 0;
  cout << "\nPlease enter a Month to check ? ";
  cin >> Month;
}
return Month;
// Problem #2
short ReadYear() { short Year = 0; }
cout << "\nPlease enter a year to check ? ";
cin >> Year;
return Year;
25 sDate ReadFullDate() {
  sDate Date;
  Date.Day = ReadDay();
  Date.Month = ReadMonth();
  Date.Year = ReadYear();
  return Date;
}
short ReadDaysToAdd() {
  short Days;
  cout << "\nHow many days to add? ";
  cin >> Days;
  return Days;
}
int main() {
  // Problem #12
  sDate Date = ReadFullDate();
  short Days = ReadDaysToAdd();
  Date = DateAddDays(Days, Date);
  cout << "\nDate after adding [" << Days << "] days is: ";
  cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
}
system("pause>0");
return 0;