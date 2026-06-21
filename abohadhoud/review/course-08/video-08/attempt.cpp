#include "../../../lib/MySmallLibrary.h"

#include <iomanip>
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
short DayOrderInDate(sDate Date) {
  short a = (14 - Date.Month) / 12;

  short y = Date.Year - a;

  short m = Date.Month + (12 * a) - 2;

  short d =
      (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

  return d;
}

string DayNameInOrder(short DayOrder) {
  const string DaysNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  return DaysNames[DayOrder];
}

string MonthNameInOrder(short MonthOrder) {
  const string Months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  return Months[MonthOrder - 1];
}
void PrintLine(short Length) {
  for (int i = 0; i < Length; i++) {
    cout << '_';
  }
}

void PrintMonthDaysOrder(sDate Date) {
  Date.Day = 1;

  for (short WeekDayNow = 0;
       Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year); WeekDayNow++) {
    if (WeekDayNow == 7) {
      cout << endl;
      WeekDayNow = 0;
    }

    if (WeekDayNow == DayOrderInDate(Date)) {
      cout << setw(5) << Date.Day++;

    }

    else {
      cout << setw(5) << 0;
    }
  }
}

void PrintMonthCalendar(sDate Date) {
  PrintLine(15);
  cout << MonthNameInOrder(Date.Month);
  PrintLine(15);
  cout << endl;
  cout << "    Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
  PrintMonthDaysOrder(Date);
}
int main() {
  sDate Date;
  Date.Year = ReadShortNumber("Please enter a year: ");
  Date.Month = ReadShortNumber("Please enter a Month: ");

  PrintMonthCalendar(Date);
  return 0;
}