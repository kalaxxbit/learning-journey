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

bool IsFristDayInMonth(sDate Date1) { return (Date1.Day == 1); }

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

bool IsFristMonthInYear(sDate Date1) { return (Date1.Month == 1); }

sDate DecreaseDateByOneDay(sDate Date) {
  if (IsFristDayInMonth(Date)) {
    if (IsFristMonthInYear(Date)) {
      Date.Year--;
      Date.Month = 12;
      Date.Day = 31;
    } else {
      Date.Month--;
      Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    }
  } else {
    Date.Day--;
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
    Date1 = DecreaseDateByOneDay(Date1);
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

sDate DecreaseDateByTenDay(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = DecreaseDateByOneDay(Date);
  }
  return Date;
}

sDate DecreaseDateByOneWeek(sDate Date) {
  for (short i = 0; i < 7; i++) {
    Date = DecreaseDateByOneDay(Date);
  }
  return Date;
}

sDate DecreaseDateByTenWeek(sDate Date) {
  for (short i = 0; i < 10; i++) {
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

sDate DecreaseDateByFiveMonth(sDate Date) {
  for (short i = 0; i < 5; i++) {
    Date = DecreaseDateByOneMonth(Date);
  }
  return Date;
}

sDate DecreaseDateByOneYear(sDate Date) {

  for (short i = 0; i < 12; i++) {
    Date = DecreaseDateByOneMonth(Date);
  }
  return Date;
}

sDate DecreaseDateByTenYears(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = DecreaseDateByOneYear(Date);
  }
  return Date;
}

sDate DecreaseDateByTenYearsFaster(sDate Date) {
  Date.Year -= 10;

  return Date;
}

sDate DecreaseDateByOneDecade(sDate Date) {

  Date = DecreaseDateByTenYearsFaster(Date);
  return Date;
}

sDate DecreaseDateByTenDecade(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = DecreaseDateByOneDecade(Date);
  }
  return Date;
}

sDate DecreaseDateByTenDecadeFaster(sDate Date) {

  Date.Year -= 100;

  return Date;
}

sDate DecreaseDateByOneCentury(sDate Date) {

  Date = DecreaseDateByTenDecade(Date);

  return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date) {
  for (short i = 0; i < 10; i++) {
    Date = DecreaseDateByOneCentury(Date);
  }
  return Date;
}

int main() {
  sDate Date = ReadDate();
  cout << ":Date After" << endl;

  Date = DecreaseDateByOneDay(Date);
  cout << "Decrease one day is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByTenDay(Date);
  cout << "Decrease 10 day is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByOneWeek(Date);
  cout << "Decrease One Week is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByTenWeek(Date);
  cout << "Decrease 10 Week is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByOneMonth(Date);
  cout << "Decrease One Month is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByFiveMonth(Date);
  cout << "Decrease 5 Month is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByOneYear(Date);
  cout << "Decrease One Year is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByTenYears(Date);
  cout << "Decrease 10 Years is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByTenYearsFaster(Date);
  cout << "Decrease 10 Years Faster is: " << ConvertDateToStringDate(Date)
       << endl;

  Date = DecreaseDateByOneDecade(Date);
  cout << "Decrease One Decade is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByTenDecade(Date);
  cout << "Decrease 10 Decade is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByTenDecadeFaster(Date);
  cout << "Decrease 10 Decade Faster is: " << ConvertDateToStringDate(Date)
       << endl;

  Date = DecreaseDateByOneCentury(Date);
  cout << "Decrease One Century is: " << ConvertDateToStringDate(Date) << endl;

  Date = DecreaseDateByOneMillennium(Date);
  cout << "Decrease One Millennium is: " << ConvertDateToStringDate(Date)
       << endl;

  return 0;
}