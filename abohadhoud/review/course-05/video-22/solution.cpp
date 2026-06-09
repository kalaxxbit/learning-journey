#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
int Number;
do
{
cout << Message << endl;
cin >> Number;
} while (Number < 0);
}
return Number;

void ReadArray(int arr[100], int& arrLength)
// & main يف ةلخدملا ةميقلا ) نزخت ( عجرتل
{
cout << "Enter number of elements : \n";
cin >> arrLength;
cout << "\n";
for (int i = 0 ; i < arrLength; i++)
// index[0] == arr يف رصنع لوأ نيزخت ناكم
{
cout << "Elements [" << i +1 << "] : ";
// [1] == arr يف رصنع ةميق لوأ
cin >> arr[i];
}
cout << endl;
}
void PrintArray(int arr[100], int arrLength)
// main يف ةنزخملا ةميقلا ءاعدتسا arrLength
{
for (int i = 0; i < arrLength; i++)
cout << arr[i] << " ";
cout << "\n";
}
int TimeRepeated(int Number, int arr[100], int arrLength)
{
int Count = 0;
for (int i = 0; i <= arrLength - 1; i++)
{
if (Number == arr[i])
Count++;
}
return Count;
}
int main()
{
int arr[100], arrLength, NumberToCheck;
ReadArray(arr, arrLength);
NumberToCheck = ReadPositiveNumber("Enter the number you want to
check : ");
cout << "\nOriginal array : ";
PrintArray(arr, arrLength);
cout << "\nNumber " << NumberToCheck;
cout << " is repeated ";
cout << TimeRepeated(NumberToCheck, arr, arrLength) << "
time(s).\n";
}