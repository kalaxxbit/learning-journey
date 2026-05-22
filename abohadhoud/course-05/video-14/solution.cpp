#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
int Number;
do
{
cout << Message << endl;
cin >> Number; // 3
}
} while (Number < 0);
return Number;
void PrintInvertedLetterPattern(int Number)
{
// Number = 3 (رطسلأا وأ فرحلأا ددع )
cout << "\n";
for (int i = 65 + Number - 1 ; i >= 65; i--)
// 67 >= 65 ? || 66 >= 65 ? ...
{
for (int j = 1 ; j <= Number - ( 65 + Number - 1 - i ); j++)
// 1 <= 3 [= 3 - "0" ( 65 + 3 - 1 - 67 ) ] || 2 <= 3 [= 3 - "0" ( 65 + 3
- 1 - 67 ) ] ...
{
cout << char(i); // CCC \n BB \n A
}
cout << endl;
}
}
int main()
{
PrintInvertedLetterPattern(ReadPositiveNumber("Pleas enter a
Positive Number ?"));
}