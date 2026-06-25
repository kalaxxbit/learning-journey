#include "../../../lib/MySmallLibrary.h"

#include <iostream>
#include <string>

using namespace std;

struct sDate {
  short Day = 1;
  short Month = 1;
  short Year = 1;
};
short ReadShortNumber(string msg) {
  short Num;
  cout << msg;
  cin >> Num;
  return Num;
}
short TotalDaysFromBeginningOfTheYear(sDate Date) {
  short TotalDays = 0;
  for (short i = 1; i < Date.Month; i++) {

    TotalDays += NumberOfDaysInAMonth(i, Date.Year);
  }
  return TotalDays + Date.Day;
}

sDate ConvertYearDaysIntoDate(short Year, short Days) {
  sDate Date;
  short RemainingDays = Days;
  short MonthDays = 0;
  Date.Year = Year;
  Date.Month = 1;
  while (true) {
    MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
    if (RemainingDays > MonthDays) {
      RemainingDays -= MonthDays;
      Date.Month++;
    } else {
      Date.Day = RemainingDays;
      break;
    }
  }
  return Date;
}

sDate AddingDaysToDate(sDate Date, short Days) {

  short MonthDays = 0;
  short RemainingDays = Days + TotalDaysFromBeginningOfTheYear(Date);
  Date.Month = 1;
  Date.Day = 1;
  while (1) {
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
sDate ReadDate() {
  sDate Date;

  Date.Day = ReadShortNumber("Please enter a Day: ");
  Date.Month = ReadShortNumber("Please enter a Month: ");
  Date.Year = ReadShortNumber("Please enter a year: ");
  return Date;
}
string ConvertDateToStringDate(sDate Date) {
  return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" +
         to_string(Date.Year);
}

bool IsLastDayInonth(sDate Date1) {
  return (Date1.Day == NumberOfDaysInAMonth(Date1.Month, Date1.Year));
}

bool IsLastMonthInYear(sDate Date1) { return (Date1.Month == 12); }
sDate IncreaseDateByOneDay(sDate Date) {
  if (IsLastDayInonth(Date)) {
    if (IsLastMonthInYear(Date)) {
      Date.Year++;
      Date.Month = 1;
      Date.Day = 1;
    } else {
      Date.Month++;
      Date.Day = 1;
    }
  } else {
    Date.Day++;
  }
  return Date;
}
int main() {
  sDate Date = ReadDate();
  Date = IncreaseDateByOneDay(Date);
  cout << "Date after adding one Day is : " << ConvertDateToStringDate(Date)
       << endl;

  return 0;
}