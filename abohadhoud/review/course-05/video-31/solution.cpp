#include#include<iostream>
<cstdlib>
using namespace std;
int ReadPositiveNumber(string Message)
{
int Number = 0;
do
{
cout << Message << endl;
cin >> Number;
} while (Number <= 0);
}
return Number;
void Swap(int& A , int& B)
{
int Temp;
}
Temp = A;
A = B;
B = Temp;

void FillArrayWith1ToNum(int arr[100], int arrLength)
{
for (int i = 0; i <= arrLength; i++)
{
arr[i] = i + 1;
}
}
int RandomNumber(int From, int To)
{
}
int RandNum = rand() % (To - From + 1) + From;
return RandNum;
void ShuffleArray(int arr[100], int arrLength)
{
for (int i = 0; i < arrLength; i++)
{
Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1,
arrLength) - 1]);
}
}
void PrintArray(int arr[100], int arrLength)
{
for (int i = 0; i < arrLength; i++)
cout << arr[i] << " ";
}
cout << "\n";
int main()
{
srand((unsigned)time(NULL));
int arr[100];
int arrLength = ReadPositiveNumber("Enter number of elements : ");
FillArrayWith1ToNum(arr, arrLength);
cout << "\nArray elements before shuffle: \n";
PrintArray(arr, arrLength);
ShuffleArray(arr, arrLength);
}
cout << "\nArray elements after shuffle: \n";
PrintArray(arr, arrLength);