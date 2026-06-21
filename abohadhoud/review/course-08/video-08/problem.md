Write a program to print Month Calendar
bool IsLeapYear(short Year)
{
// if year is divisible by 4
AND not divisible by 100
// OR if year is divisible by
400
// then it is a leap year
return (Year % 4 == 0 && Year
% 100 != 0) || (Year % 400 == 0);
}
// Problem #7
short DayOfWeekOrder(short Day,
short Month, short Year)
{
short a, y, m;
a = (14 - Month) / 12;
y = Year - a;
m = Month + (12 * a) - 2;
Please enter a year to check ? 2023
Please enter a Month to check ? 8
__________________Aug_______________
Sun Mon Tue Wed Thu Fri Sat
0
 0
 1
 2
 3
 4
 5
6
 7
 8
 9
 10
 11
 12
13
 14
 15
 16
 17
 18
 19
// Gregorian:
//0:sun, 1:Mon, 2:Tue...etc.
return (Day + y + (y / 4) -
(y / 100) + (y / 400) + ((31 * m) /
12)) % 7;
}
20
 21
 22
 23
 24
 25
 26
27
 28
 29
 30
 31
____________________________