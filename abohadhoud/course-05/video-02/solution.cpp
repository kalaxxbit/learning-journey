#include <iostream>
using namespace std;
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };
int ReadPositiveNumber(string Message)
{
int Number = 0;
do{
cout << Message << endl;
cin >> Number; // 10
} while (Number <= 0);
}
return Number;
enPrimNotPrime CheckPrime(int Number)
{
// Number = 10
int M = round(Number / 2); // 10 / 2 = 5
for (int Counter = 2; Counter <= M; Counter++) // 2 <= 5 ?
{
if (Number % Counter == 0) // 10 % 2 == 0 ? Yes , is (Not Prime)
return enPrimNotPrime::NotPrime;
}
return enPrimNotPrime::Prime; // 11 % 2 == 0 ? No , is (Prime)
}
void PrintPrimeNumbersFrom1ToNumber(int Number)
{
cout << "\n Prime Numbers from " << 1 << " To " << Number << " are :
\n";
for (int i = 1; i <= Number; i++) // 1 <= 10 ? راركتلا ةقلح يف لخدا , معن
{
if (CheckPrime(i) == enPrimNotPrime::Prime)
// CheckPrime(1 ...2 3 to 10) == enPrimNotPrime::Prime
{
cout << i << endl; // Print ( 1 \n 2 \n 3 \n 5 ....)
}
}
}
int main()
{
PrintPrimeNumbersFrom1ToNumber(ReadPositiveNumber("Pleas enter a
positive number "));
}