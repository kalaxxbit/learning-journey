#include "../../../lib/MySmallLibrary.h"

#include <ctime>
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

bool IsDate1LessThanDate2(sDate Date1, sDate Date2) {

  return (Date1.Year < Date2.Year)
             ? true
             : (Date1.Year == Date2.Year
                    ? (Date1.Month < Date2.Month)
                          ? true
                          : (Date1.Month == Date2.Month
                                 ? ((Date1.Day < Date2.Day))
                                 : false)
                    : false);
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
void SwapDates(sDate &Date1, sDate &Date2) {
  sDate Temp = Date1;
  Date1 = Date2;
  Date2 = Temp;
}
short CalculateDifferencInDays(sDate Date1, sDate Date2,
                               bool IncludingEndDay = 0) {
  short Counter = 0;
  bool Neg = false;
  if (IsDate1LessThanDate2(Date2, Date1)) {
    SwapDates(Date1, Date2);
    Neg = true;
  }

  while (IsDate1LessThanDate2(Date1, Date2)) {
    Date1 = IncreaseDateByOneDay(Date1);
    Counter++;
  }
  Counter = (IncludingEndDay ? ++Counter : Counter);
  return Neg ? Counter : Counter * -1;
}

sDate GetLocalDate() {
  sDate LocalDate;
  std::time_t currentTime = std::time(nullptr);
  std::tm *localDate = std::localtime(&currentTime);
  LocalDate.Year = localDate->tm_year + 1900;
  LocalDate.Month = localDate->tm_mon + 1;
  LocalDate.Day = localDate->tm_mday;
  return LocalDate;
}

sDate IncreaseDateByTenDay(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = IncreaseDateByOneDay(Date);
  }
  return Date;
}

sDate IncreaseDateByOneWeek(sDate Date) {
  for (short i = 0; i < 7; i++) {
    Date = IncreaseDateByOneDay(Date);
  }
  return Date;
}

sDate IncreaseDateByTenWeek(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = IncreaseDateByOneWeek(Date);
  }
  return Date;
}

sDate IncreaseDateByOneMonth(sDate Date) {
  short DaysLength = NumberOfDaysInAMonth(Date.Month, Date.Year);

  for (short i = 0; i < DaysLength; i++) {
    Date = IncreaseDateByOneDay(Date);
  }
  return Date;
}

sDate IncreaseDateByFiveMonth(sDate Date) {
  for (short i = 0; i < 5; i++) {
    Date = IncreaseDateByOneMonth(Date);
  }
  return Date;
}

sDate IncreaseDateByOneYear(sDate Date) {

  for (short i = 0; i < 12; i++) {
    Date = IncreaseDateByOneMonth(Date);
  }
  return Date;
}

sDate IncreaseDateByTenYears(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = IncreaseDateByOneYear(Date);
  }
  return Date;
}

sDate IncreaseDateByTenYearsFaster(sDate Date) {
  Date.Year += 10;
  if (Date.Month == 2) {
    if (Date.Day > NumberOfDaysInAMonth(2, Date.Year)) {
      Date.Day = 1;
      Date.Month++;
    }
  }

  return Date;
}

sDate IncreaseDateByOneDecade(sDate Date) {

  Date = IncreaseDateByTenYearsFaster(Date);
  return Date;
}

sDate IncreaseDateByTenDecade(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = IncreaseDateByOneDecade(Date);
  }
  return Date;
}

sDate IncreaseDateByTenDecadeFaster(sDate Date) {

  Date.Year += 100;
  if (Date.Month == 2) {
    if (Date.Day > NumberOfDaysInAMonth(2, Date.Year)) {
      Date.Day = 1;
      Date.Month++;
    }
  }

  return Date;
}

sDate IncreaseDateByOneCentury(sDate Date) {

  Date = IncreaseDateByTenDecade(Date);

  return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = IncreaseDateByOneCentury(Date);
  }
  return Date;
}

int main() {
  sDate Date = ReadDate();
  cout << ":Date After" << endl;

  Date = IncreaseDateByOneDay(Date);
  cout << "Adding one day is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByTenDay(Date);
  cout << "Adding 10 day is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByOneWeek(Date);
  cout << "Adding One Week is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByTenWeek(Date);
  cout << "Adding 10 Week is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByOneMonth(Date);
  cout << "Adding One Month is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByFiveMonth(Date);
  cout << "Adding 5 Month is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByOneYear(Date);
  cout << "Adding One Year is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByTenYears(Date);
  cout << "Adding 10 Years is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByTenYearsFaster(Date);
  cout << "Adding 10 Years Faster is: " << ConvertDateToStringDate(Date)
       << endl;

  Date = IncreaseDateByOneDecade(Date);
  cout << "Adding One Decade is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByTenDecade(Date);
  cout << "Adding 10 Decade is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByTenDecadeFaster(Date);
  cout << "Adding 10 Decade Faster is: " << ConvertDateToStringDate(Date)
       << endl;

  Date = IncreaseDateByOneCentury(Date);
  cout << "Adding One Century is: " << ConvertDateToStringDate(Date) << endl;

  Date = IncreaseDateByOneMillennium(Date);
  cout << "Adding One Millennium is: " << ConvertDateToStringDate(Date) << endl;

  return 0;
}