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
void PrintDigits(int Number)
{
// Number = 1234
int Remainder = 0;
while (Number > 0) // 1234 > 0 ? | 123 > 0 ? ....
{
Remainder = Number % 10; // 1234 % 10 = 4 | 123 % 10 = 3 ....
Number = Number / 10; //(int) 1234 / 10 = 123 | 123 / 10 = 12
....
cout << Remainder << endl; // Print ( 4 \n 3 \n 2 \n 1 )
}
}
int main()
{
PrintDigits(ReadPositiveNumber("Pleas enter a positie Number ?"));
}