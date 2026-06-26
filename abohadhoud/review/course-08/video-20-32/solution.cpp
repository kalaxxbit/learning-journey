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
// Problem #6
short NumberOfDaysInAMonth(short Month, short Year) {
  if (Month < 1 || Month > 12)
    return 0;
  int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
// Problem #15
bool IsLastDayInMonth(sDate Date) {
  return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month) { return (Month == 12); }
Write a program to read a Date and make a functions to Increase Date as follows
    : Please enter a Day to check
      ? 18 Please enter a Month to check ? 8 Please enter a year to check
                                               ? 2023
                                               : Date After Adding one day is
                                         : -01 19 / 8 / 2023 Adding 10 days is
      : -02 29 / 8 / 2023 Adding one week is : -03 5 / 9 /
                                               2023 Adding 10 weeks is
    : -04 14 /
      11 / 2023 Adding one month is : -05 14 / 12 /
                                      2023 Adding 5 months is
    : -06 14 /
      5 / 2024 Adding one year is : -07 14 / 5 /
                                    2025 Adding 10 Years is
    : -08 14 /
      5 /
      2035 45
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
}
return Month;
// Problem #2
short ReadYear() { short Year = 0; }
cout << "\nPlease enter a year to check ? ";
cin >> Year;
return Year;
Adding 10 Years(faster) is : -09 14 / 5 /
                             2045 Adding one Decade is
    : -10 14 /
      5 / 2055 Adding 10 Decades is : -11 14 / 5 /
                                      2155 Adding 10 Decade(faster) -
    12 is : 14 / 5 / 2255 Adding One Century is : -13 14 / 5 /
                                                  2355 Adding One Millennium is
    : -14 14 /
      5 /
      3355 46
      // Problem #12
      sDate ReadFullDate() {
  sDate Date;
  Date.Day = ReadDay();
  Date.Month = ReadMonth();
  Date.Year = ReadYear();
  return Date;
}
// Problems From 20 To 32
sDate IncreaseDateByXDays(short Days, sDate Date) {
  for (short i = 1; i <= Days; i++) {
    Date = IncreaseDateByOneDay(Date);
  }
  return Date;
}
sDate IncreaseDateByOneWeek(sDate Date) {
  for (int i = 1; i <= 7; i++) {
    Date = IncreaseDateByOneDay(Date);
  }
  return Date;
}
sDate IncreaseDateByXWeeks(short Weeks, sDate Date) {
  for (short i = 1; i <= Weeks; i++) {
    Date = IncreaseDateByOneWeek(Date);
  }
  return Date;
}
sDate IncreaseDateByOneMonth(sDate Date) {
  if (Date.Month == 12) {
    Date.Month = 1;
    Date.Year++;
  } else {
    Date.Month++;
  }
  // last check day in date should not exceed max days in the current month
  //  example if date is 31/1/2022 increasing one month should not be
  31 / 2 / 2022, it should
                 // be 28/2/2022
                 short NumberOfDaysInCurrentMonth =
                     NumberOfDaysInAMonth(Date.Month, Date.Year);
  if (Date.Day > NumberOfDaysInCurrentMonth) {
    Date.Day = NumberOfDaysInCurrentMonth;
  }
  return Date;
}
47 sDate IncreaseDateByXMonths(short Months, sDate Date) {
  for (short i = 1; i <= Months; i++) {
    Date = IncreaseDateByOneMonth(Date);
  }
  return Date;
}
sDate IncreaseDateByOneYear(sDate Date) {
  Date.Year++;
  return Date;
}
sDate IncreaseDateByXYears(short Years, sDate Date) {
  for (short i = 1; i <= Years; i++) {
    Date = IncreaseDateByOneYear(Date);
  }
  return Date;
}
sDate IncreaseDateByXYearsFaster(short Years, sDate Date) {
  Date.Year += Years;
  return Date;
}
sDate IncreaseDateByOneDecade(sDate Date) {
  // Period of 10 years
  Date.Year += 10;
  return Date;
}
sDate IncreaseDateByXDecades(short Decade, sDate Date) {
  for (short i = 1; i <= Decade * 10; i++) {
    Date = IncreaseDateByOneYear(Date);
  }
  return Date;
}
sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date) {
  Date.Year += Decade * 10;
  return Date;
}
sDate IncreaseDateByOneCentury(sDate Date) {
  // Period of 100 years
  Date.Year += 100;
  return Date;
}
sDate IncreaseDateByOneMillennium(sDate Date) {
  // Period of 1000 years
  Date.Year += 1000;
  return Date;
}
48 int {}
main()
    // Problems From 20 To 32
    sDate Date1 = ReadFullDate();
cout << "\nDate After: \n";
Date1 = IncreaseDateByOneDay(Date1);
cout << "\n01-Adding one day is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByXDays(10, Date1);
cout << "\n02-Adding 10 days is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByOneWeek(Date1);
cout << "\n03-Adding one week is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByXWeeks(10, Date1);
cout << "\n04-Adding 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByOneMonth(Date1);
cout << "\n05-Adding one month is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByXMonths(5, Date1);
cout << "\n06-Adding 5 months is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByOneYear(Date1);
cout << "\n07-Adding one year is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByXYears(10, Date1);
cout << "\n08-Adding 10 Years is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByXYearsFaster(10, Date1);
cout << "\n09-Adding 10 Years (faster) is: " << Date1.Day << "/" << Date1.Month
     << "/" << Date1.Year;
Date1 = IncreaseDateByOneDecade(Date1);
cout << "\n10-Adding one Decade is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByXDecades(10, Date1);
cout << "\n11-Adding 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByXDecadesFaster(10, Date1);
cout << "\n12-Adding 10 Decade (faster) is: " << Date1.Day << "/" << Date1.Month
     << "/" << Date1.Year;
Date1 = IncreaseDateByOneCentury(Date1);
cout << "\n13-Adding One Century is: " << Date1.Day << "/" << Date1.Month << "/"
     << Date1.Year;
Date1 = IncreaseDateByOneMillennium(Date1);
cout << "\n14-Adding One Millennium is: " << Date1.Day << "/" << Date1.Month
     << "/" << Date1.Year;
system("pause>0");
return 0;