Write a program to print
Total Days from the
beginning of Year
Please enter a Day to check ?
13
Please enter a Month to check
? 8
Please enter a year to check ?
2023
short NumberOfDaysInAMonth(short Month, short Year)
{
if (Month < 1 || Month > 12)
return 0;
int NumberOfDays[12] = {
31,28,31,30,31,30,31,31,30,31,30,31 };
Number of Days from
beginning of the Year Is : 225