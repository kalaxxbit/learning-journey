#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
int Number = 0;
do
{
cout << Message << endl;
cin >> Number; // 500
} while (Number <= 0);
return Number;
}
bool IsPerfectNumber(int Number)
{
// Number = 500
int Sum = 0; // ةميق ريغتم لكل نوكي لضفلأا
for (int i = 1; i < Number; i++) // 1 < 500 ?
{
if (Number % i == 0) // 500 % 1 = 0 ?; 500 % 2 = 0...(to 500
< 499 ). 499 % 1 = 0 ...
Sum += i; // 1 + 2 + 4 ...
}
return Number == Sum; // 500 == 592 is false .. ( true = 6 , 28 ,
496 )
}
void PrintPerfectNumberFrom1ToNum(int Number)
{
cout << "\n";
for (int i = 1; i < Number; i++) // 1 < 500 ?
{
if (IsPerfectNumber(i)) // IsPerfectNumber(500) ? ناك اذإ لوبقملا
طقف حيحص باوجلا
cout << i << endl; // Print ( true = 6 , 28 , 496 )
}
}
int main()
{
PrintPerfectNumberFrom1ToNum(ReadPositiveNumber("Pleas enter a
positive number ? "));
}