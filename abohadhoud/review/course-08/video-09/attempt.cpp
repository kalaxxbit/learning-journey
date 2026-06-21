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

short PastMonthDays(sDate Date) {
  if (Date.Month == 1) {
    return NumberOfDaysInAMonth(12, Date.Year - 1);
  }
  return NumberOfDaysInAMonth(Date.Month - 1, Date.Year);
}
void PrintMonthDaysOrder(sDate Date) {
  Date.Day = 1;
  short Current = DayOrderInDate(Date);
  short PastMonthDaysMod = PastMonthDays(Date) - Current + 1;
  short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
  int i;
  for (i = 0; i < Current; i++) {

    cout << setw(5) << PastMonthDaysMod + i;
  }

  for (int j = 1; j <= MonthDays; j++) {
    cout << setw(5) << j;
    if (++i == 7) {
      cout << endl;
      i = 0;
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
  cout << endl;
}

void PrintYearCalendar(sDate Date) {
  PrintLine(30);
  cout << endl;
  cout << setw(5) << "\tCalendar –" << Date.Year << endl;
  PrintLine(30);
  cout << endl;
  while (Date.Month <= 12) {
    PrintMonthCalendar(Date);

    PrintLine(30);
    cout << endl;

    Date.Month++;
  }
}

int main() {
  sDate Date;
  Date.Year = ReadShortNumber("Please enter a year: ");

  PrintYearCalendar(Date);
  return 0;
}