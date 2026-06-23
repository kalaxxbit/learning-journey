#include <iostream>
#include <string>
using namespace std;
// Problem #11
struct {};
sDate shortshortshortYear;
Month;
Day;
// Problem #13
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
  return (Date1.Year < Date2.Year)
             ? true
             : ((Date1.Year == Date2.Year)
                    ? (Date1.Month < Date2.Month
                           ? true
                           : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day
                                                         : false))
                    : false);
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
short ReadYear() {
  short Year = 0;
  cout << "\nPlease enter a year to check ? ";
  cin >> Year;
}
return Year;
Write a program to read Date1,
    Date2 and check if Date1 Less than Date2 Please enter a Day to check
    ? 15 Please enter a Month to check
    ? 8 Please enter a year to check
    ? 2023 Please enter a Day to check
    ? 15 Please enter a Month to check
    ? 9 Please enter a year to check
    ? 2023 .Yes,
    Date1 is Less than Date2 27 sDate ReadFullDate() {
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
  // Problem #13
  sDate Date1 = ReadFullDate();
  cout << "\n\n";
  sDate Date2 = ReadFullDate();
  if (IsDate1BeforeDate2(Date1, Date2))
    cout << "\nYes, Date1 is Less than Date2.";
}
else cout << "\nNo, Date1 is NOT Less than Date2.";
system("pause>0");
return 0;