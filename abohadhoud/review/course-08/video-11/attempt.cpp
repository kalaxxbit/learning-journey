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
  Date.Year = Year;
  short MonthLengthNow = 0;
  short YearLength = 365 + isLeapYear(Year);
  for (short i = 1; i < YearLength; i++) {
    MonthLengthNow = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Days > MonthLengthNow) {
      Days -= MonthLengthNow;
      Date.Month++;
    } else {
      Date.Day = Days;
    }
  }
  return Date;
}
string ConvertDateToStringDate(sDate Date) {
  return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" +
         to_string(Date.Year);
}
int main() {
  sDate Date;
  Date.Day = ReadShortNumber("Please enter a Day: ");
  Date.Month = ReadShortNumber("Please enter a Month: ");
  Date.Year = ReadShortNumber("Please enter a year: ");
  short TotalDays = TotalDaysFromBeginningOfTheYear(Date);
  cout << "Number of Days from beginning of the Year Is : " << TotalDays
       << endl;
  cout << "Date For [" << TotalDays << "] is : "
       << ConvertDateToStringDate(ConvertYearDaysIntoDate(Date.Year, TotalDays))
       << endl;
  return 0;
}