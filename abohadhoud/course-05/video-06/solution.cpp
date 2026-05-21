#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
int Number = 0;
do
{
cout << Message << endl;
cin >> Number; // 1234
} while (Number <= 0);
return Number;
}
int PrintSumOfDigits(int Number)
{
// Number = 1234
int Sum = 0, Remainder = 0;
while (Number > 0) // 1234 > 0 ? | 123 = 0 ? ...
{
Remainder = Number % 10; // 1234 % 10 = 4 | 123 % 10 = 3 ....
Number = Number / 10; //(int) 1234 / 10 = 123 | 123 / 10 = 12
....
Sum = Sum + Remainder; // 0 + 4 = 4 | 4 + 3 = 7 ....
}
return Sum; // Sum = 10
}
int main()
{
cout << "\n Sum Of Digits = "
<< PrintSumOfDigits(ReadPositiveNumber("Pleas enter a positie
Number ?"))
<< endl;
}