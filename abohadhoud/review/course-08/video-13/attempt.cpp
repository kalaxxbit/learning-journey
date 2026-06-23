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

bool IsDate1LessThanDate2(sDate Date1, sDate Date2) {

  if (Date1.Year > Date2.Year) {
    return true;
  } else if (Date1.Month > Date2.Month) {
    return true;
  } else if (Date1.Day > Date2.Day) {
    return true;
  }
  return false;
}

int main() {
  sDate Date1 = ReadDate();
  sDate Date2 = ReadDate();
  if (IsDate1LessThanDate2(Date1, Date2)) {
    cout << ".Yes, Date1 is Less than Date2" << endl;
  } else {
    cout << ".No, Date1 is Not Less than Date2" << endl;
  }
  return 0;
}