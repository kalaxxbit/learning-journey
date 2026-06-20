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
short DayOrderInDate(sDate Date) {
  short a = (14 - Date.Month) / 12;

  short y = Date.Year - a;

  short m = Date.Month + (12 * a) - 2;

  short d =
      (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

  return d;
}
string DateToText(sDate Date) {
  return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" +
         to_string(Date.Year);
}

string DayNameInOrder(short DayOrder) {
  const string DaysNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  return DaysNames[DayOrder];
}
int main() {
  sDate Date;
  Date.Year = ReadShortNumber("Please enter a year: ");
  Date.Month = ReadShortNumber("Please enter a Month: ");

  Date.Day = ReadShortNumber("Please enter a Day: ");

  cout << "Date\t:" << DateToText(Date) << endl;
  cout << "Day Order : " << DayOrderInDate(Date) << endl;
  cout << "Day Name : " << DayNameInOrder(DayOrderInDate(Date)) << endl;
  return 0;
}
