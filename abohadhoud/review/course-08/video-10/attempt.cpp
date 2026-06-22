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
int main() {
  sDate Date;
  Date.Day = ReadShortNumber("Please enter a Day: ");
  Date.Month = ReadShortNumber("Please enter a Month: ");
  Date.Year = ReadShortNumber("Please enter a year: ");
  cout << "Number of Days from beginning of the Year Is : "
       << TotalDaysFromBeginningOfTheYear(Date);
  return 0;
}