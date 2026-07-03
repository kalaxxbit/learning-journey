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
// Problem #57
enum enDateCompare {Before = -1 , Equal = 0 , After
= 1};

enDateCompare CompareDates(sDate Date1 , sDate Date2)
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
// Problem #60
bool isDateInPeriod(stDate Date, stPeriod Period) 
{
return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
||
CompareDates(Date, Period.EndDate) == enDateCompare::After);
}
// Problem #7
short ReadDay()
{
short Day = 0;
cout << "\nPlease enter a Day to check ? ";
cin >> Day;
return Day;
}
// Problem #5
short ReadMonth()
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
// Problem #60
cout << "\nEnter Period :"; 
stPeriod Period = ReadPeriod(); 
cout << "\nEnter Date to check:\n";
stDate Date = ReadFullDate();
if (isDateInPeriod(Date, Period)) 
cout << "\nYes, Date is within period\n";
else 
cout << "\nNo, Date is NOT within period\n"; 
system("pause>0");
return 0;
}