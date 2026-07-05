#include <iostream>
using namespace std;
// Problem #11
struct sDate
{
short Year;
short Month;
short Day;
};
// Problem #58
struct stPeriod
{ 
stDate StartDate;
stDate EndDate;
};
// Problem #13
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) 
{
return (Date1.Year < Date2.Year) ? true : 
((Date1.Year == Date2.Year) ? 
(Date1.Month < Date2.Month ? true : 
(Date1.Month == Date2.Month ? 
Date1.Day < Date2.Day : false)) 
: false); 
}
// Problem #14
bool IsDate1EqualDate2(sDate Date1, sDate Date2) 
{
return (Date1.Year == Date2.Year ) ? (( 
Date1.Month == Date2.Month ) ? 
((Date1.Day == Date2.Day) ? true : 
false ) : false ) : false ;
}
// Problem #56
bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
return (! IsDate1BeforeDate2(Date1, Date2) 
&& ! IsDate1EqualDate2(Date1, Date2));
}
// Problem #3
bool IsLeapYear(short Year)
{
return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}short NumberOfDaysInAMonth(short Month, short Year)
{
if (Month < 1 || Month > 12)
return 0;
int NumberOfDays[12] = { 
31,28,31,30,31,30,31,31,30,31,30,31 };
return (Month == 2) ? (IsLeapYear(Year) ? 29 
: 28) : NumberOfDays[Month - 1];
}
// Problem #15
bool IsLastDayInMonth(sDate Date)
{
return (Date.Day == 
NumberOfDaysInAMonth(Date.Month, Date.Year)); 
}
bool IsLastMonthInYear(short Month) 
{
return (Month == 12); 
}
// Problem #16
sDate IncreaseDateByOneDay(sDate Date) 
{
if (IsLastDayInMonth(Date)) 
{
if (IsLastMonthInYear(Date.Month)) 
{
Date.Month = 1;
Date.Day = 1; 
Date.Year++; 
}
else
{
Date.Day = 1; 
Date.Month++; 
}
}
else
{
Date.Day++;
}
return Date; 
}int GetDifferenceInDays(stDate Date1 , stDate Date2 , bool IncludeEndDay = false)
{
int Days = 0;
short SwapFlagValue = 1;
if (! IsDate1BeforeDate2(Date1, Date2))
{
SwapDates(Date1, Date2);
SwapFlagValue = -1;
}
while (IsDate1BeforeDate2(Date1, Date2))
{
Days++;
Date1 = IncreaseDateByOneDay(Date1);
}
return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}
// Problem #57
enum enDateCompare {Before = -1 , Equal = 0 , After = 1};
enDateCompare CompareDates(stDate Date1 , stDate Date2)
{
if(IsDate1BeforeDate2(Date1, Date2))
return enDateCompare::Before; 
if (IsDate1EqualDate2(Date1, Date2)) 
return enDateCompare::Equal; 
/* if (IsDate1AfterDate2(Date1,Date2))
return enDateCompare::After;*/
//this is faster
return enDateCompare::After;
}
// Problem #58
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
if (
CompareDates(Period2.EndDate, Period1.StartDate) == 
enDateCompare::Before
||
CompareDates(Period2.StartDate, Period1.EndDate) == 
enDateCompare::After
)
return false;
else
return true;
}int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
return GetDifferenceInDays(Period.StartDate, Period.EndDate, 
IncludeEndDate); 
}
// Problem #60
bool isDateInPeriod(stDate Date, stPeriod Period) 
{
return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
||
CompareDates(Date, Period.EndDate) == enDateCompare::After);
}
// Problem #61
int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
int Period1Length = PeriodLengthInDays(Period1, true);
int Period2Length = PeriodLengthInDays(Period2, true);
int OverlapDays = 0;
if (! IsOverlapPeriods(Period1, Period2))
return 0; 
if (Period1Length < Period2Length) 
{
while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
{
if (isDateInPeriod(Period1.StartDate, Period2))
OverlapDays++; 
Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
}
}
else
{
while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
{
if (isDateInPeriod(Period2.StartDate, Period1))
OverlapDays++;
Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
}
}
return OverlapDays; 
}
// Problem #7
short ReadDay()
{
short Day = 0;
cout << "\nPlease enter a Day to check ? ";
cin >> Day;
return Day;
}short ReadMonth()
{
short Month = 0;
cout << "\nPlease enter a Month to check ? ";
cin >> Month;
return Month;
}
// Problem #2
short ReadYear()
{
short Year = 0;
cout << "\nPlease enter a year to check ? ";
cin >> Year;
return Year;
}
// Problem #12
sDate ReadFullDate()
{
sDate Date;
Date.Day = ReadDay();
Date.Month = ReadMonth();
Date.Year = ReadYear();
return Date;
}
// Problem #58
stPeriod ReadPeriod()
{
stPeriod Period; 
cout << "\nEnter Start Date:\n"; 
Period.StartDate = ReadFullDate(); 
cout << "\nEnter End Date:\n"; 
Period.EndDate = ReadFullDate();
return Period; 
}
int main()
{
// Problem #61
cout << "\nEnter Period 1 :";
stPeriod Period1 = ReadPeriod();
cout << "\nEnter Period 2 :"; 
stPeriod Period2 = ReadPeriod();
cout << "\nOverlap Days Count Is: "
<< CountOverlapDays(Period1, Period2); 
system("pause>0");
return 0;
}