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


struct stPeriod {
	sDate DateStart;
	sDate DateEnd;
};

enum enDateCompare{
	After=1,
	Equal=0,
	Before=-1
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

sDate ReadDate() {
  sDate Date;

  Date.Day = ReadShortNumber("Please enter a Day: ");
  Date.Month = ReadShortNumber("Please enter a Month: ");
  Date.Year = ReadShortNumber("Please enter a year: ");
  return Date;
}





stPeriod ReadPeriod() {
  stPeriod Period;
  Period.DateStart=ReadDate();
  Period.DateEnd=ReadDate();
  return Period;
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

bool IsFristMonthInYear(sDate Date1) { return (Date1.Month == 1); }
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

bool IsWeekEnd(sDate Date) {
  // Weekends are Fri and Sat
  short DayIndex = DayOrderInDate(Date);
  return (DayIndex == 5 || DayIndex == 6);
}
sDate VacationReturnDate(sDate DateFrom,short VacationDays){
	sDate VacationEndDate=DateFrom;
	short Counter=VacationDays;
	while(Counter>0){
		if(!IsWeekEnd(VacationEndDate)){
			Counter--;
		}
		
		VacationEndDate=IncreaseDateByOneDay(VacationEndDate);
	}
	return VacationEndDate;
	
}




bool IsDatesEquals(sDate Date1, sDate Date2) {

  return ((Date1.Year==Date2.Year)&&(Date1.Month==Date2.Month)&&(Date1.Day==Date2.Day));
  
}
bool IsDate1BigThanDate2(sDate Date1, sDate Date2) {

  return !(IsDate1LessThanDate2(Date1,Date2)&&!IsDatesEquals(Date1,Date2));
  
}

short CompareDates(sDate Date1, sDate Date2){
	if(IsDatesEquals(Date1,Date2)){
		return Equal;}
		
	else if(IsDate1BigThanDate2(Date1,Date2)){
		return After;}
		
	
		return Before;
}

bool CheckPeriodsIsOverlap(stPeriod PeriodOne,stPeriod PeriodTow){
	switch (CompareDates(PeriodOne.DateEnd,PeriodTow.DateStart)){
		case Equal:
		return true;
		case After:
		return true ;
		default:
		return false ;
		
	}
	
	return false;
}

short PeriodLength(stPeriod Period,bool IncludeLastDay=true){
	return CalculateDifferencInDays(Period.DateEnd,Period.DateStart,IncludeLastDay);
}

bool IsDateWithinPeriod(sDate Date, stPeriod Period){
 if(CompareDates(Date,Period.DateEnd)==After){
 	return false;
 }else if(CompareDates(Date,Period.DateStart)==Before){
 	return false;
 }
 return true;
	
}
int main() {
 
  sDate Date=ReadDate();
   stPeriod Period=ReadPeriod();
  if(IsDateWithinPeriod( Date,  Period)){
  	cout<<"Yes , Date within the period"<<endl;
  }else{
  	
  	cout<<"No , Date Not within the period"<<endl;}




  return 0;
}