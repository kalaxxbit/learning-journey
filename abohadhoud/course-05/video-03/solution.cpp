#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
int Number = 0;
do
{
cout << Message << endl;
cin >> Number; // 28
} while (Number <= 0);
return Number;
}
bool IsPerfectNumber(int Number)
{
// Number = 28
int Sum = 0; // ةميق ريغتم لكل نوكي لضفلأا
for (int i = 1; i < Number; i++) // 1 < 28 ?
{
if (Number % i == 0) // 28 % 1 = 0 ?; 28 % 2 = 0 ?...
Sum += i; // 1 + 2 + 4 ...
}
return Number == Sum; // 28 == 28 ? , true (or false )
}
void PrintResult(int Number)
{
if (IsPerfectNumber(Number)) // true(28)
cout << "\n " << Number << " Is Perfect Number \n";
else // false(12)
cout << "\n " << Number << " Is Not Perfect Number \n";
}
int main()
{
PrintResult(ReadPositiveNumber("Pleas enter a positive number "));
}