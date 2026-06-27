#include <iostream>
#include <string>
using namespace std;
// Problem #11
struct sDate {
  short Year;
  short Month;
  short Day;
};
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
// Problems From 33 To 46
sDate DecreaseDateByOneDay(sDate Date) {
  if (Date.Day == 1) {
    if (Date.Month == 1) {
      Date.Month = 12;
      Date.Day = 31;
      Date.Year--;
    } else {
      Date.Month--;
      Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    }
  } else {

    Date.Day--;
  }
  return Date;
}

short ReadShortNumber(string msg) {
  short Num;
  cout << msg;
  cin >> Num;
  return Num;
}
sDate ReadFullDate() {
  sDate Date;

  Date.Day = ReadShortNumber("Please enter a Day: ");
  Date.Month = ReadShortNumber("Please enter a Month: ");
  Date.Year = ReadShortNumber("Please enter a year: ");
  return Date;
}

sDate DecreaseDateByXDays(short Days, sDate Date) {
  for (short i = 1; i <= Days; i++) {
    Date = DecreaseDateByOneDay(Date);
  }
  return Date;
}
sDate DecreaseDateByOneWeek(sDate Date) {
  for (int i = 1; i <= 7; i++) {
    Date = DecreaseDateByOneDay(Date);
  }
  return Date;
}
sDate DecreaseDateByXWeeks(short Weeks, sDate Date) {
  for (short i = 1; i <= Weeks; i++) {
    Date = DecreaseDateByOneWeek(Date);
  }
  return Date;
}
sDate DecreaseDateByOneMonth(sDate Date) {
  if (Date.Month == 1) {
    Date.Month = 12;
    Date.Year--;
  } else {
    Date.Month--;
  }
  short NumberOfDaysInCurrentMonth =
      NumberOfDaysInAMonth(Date.Month, Date.Year);
  if (Date.Day > NumberOfDaysInCurrentMonth) {
    Date.Day = NumberOfDaysInCurrentMonth;
  }
  return Date;
}
sDate DecreaseDateByXMonths(short Months, sDate Date) {
  for (short i = 1; i <= Months; i++) {
    Date = DecreaseDateByOneMonth(Date);
  }
  return Date;
}

sDate DecreaseDateByOneYear(sDate Date) {
  Date.Year--;
  return Date;
}
sDate DecreaseDateByXYears(short Years, sDate Date) {
  for (short i = 1; i <= Years; i++) {
    Date = DecreaseDateByOneYear(Date);
  }
  return Date;
}
sDate DecreaseDateByXYearsFaster(short Years, sDate Date) {
  Date.Year -= Years;
  return Date;
}
sDate DecreaseDateByOneDecade(sDate Date) {
  // Period of 10 years
  Date.Year -= 10;
  return Date;
}
sDate DecreaseDateByXDecades(short Decade, sDate Date) {
  for (short i = 1; i <= Decade * 10; i++) {
    Date = DecreaseDateByOneYear(Date);
  }
  return Date;
}
sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date) {
  Date.Year -= Decade * 10;
  return Date;
}
sDate DecreaseDateByOneCentury(sDate Date) {
  // Period of 100 years
  Date.Year -= 100;
  return Date;
}
sDate DecreaseDateByOneMillennium(sDate Date) {
  // Period of 1000 years
  Date.Year -= 1000;
  return Date;
}
int main() {
  // Problems From 33 To 46
  sDate Date1 = ReadFullDate();
  cout << "\nDate After: \n";
  Date1 = DecreaseDateByOneDay(Date1);
  cout << "\n01-Subtracting one day is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByXDays(10, Date1);
  cout << "\n02-Subtracting 10 days is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByOneWeek(Date1);
  cout << "\n03-Subtracting one week is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByXWeeks(10, Date1);
  cout << "\n04-Subtracting 10 weeks is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByOneMonth(Date1);
  cout << "\n05-Subtracting one month is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByXMonths(5, Date1);
  cout << "\n06-Subtracting 5 months is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByOneYear(Date1);
  cout << "\n07-Subtracting one year is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByXYears(10, Date1);
  cout << "\n08-Subtracting 10 Years is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByXYearsFaster(10, Date1);
  cout << "\n09-Subtracting 10 Years (faster) is: " << Date1.Day << "/"
       << Date1.Month << "/" << Date1.Year;
  Date1 = DecreaseDateByOneDecade(Date1);
  cout << "\n10-Subtracting one Decade is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByXDecades(10, Date1);
  cout << "\n11-Subtracting 10 Decades is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByXDecadesFaster(10, Date1);
  cout << "\n12-Subtracting 10 Decade (faster) is: " << Date1.Day << "/"
       << Date1.Month << "/" << Date1.Year;
  Date1 = DecreaseDateByOneCentury(Date1);
  cout << "\n13-Subtracting One Century is: " << Date1.Day << "/" << Date1.Month
       << "/" << Date1.Year;
  Date1 = DecreaseDateByOneMillennium(Date1);
  cout << "\n14-Subtracting One Millennium is: " << Date1.Day << "/"
       << Date1.Month << "/" << Date1.Year;

  return 0;
}