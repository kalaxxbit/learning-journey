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
int RandomNumber(int From, int To)
{
}
int RandNum = rand() % (To - From + 1) + From;
return RandNum;

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
for (int i = 0 ; i < arrLength; i++)
arr[i] = RandomNumber(1, 100);
}
void SumOf2Arrays(int arr[100], int arr2[100], int arrSum[100], int
arrLength)
{
for (int i = 0; i < arrLength; i++)
{
arrSum[i] = arr[i] + arr2[i];
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
int arr[100] ,arr2[100], arrSum[100];
int arrLength = ReadPositiveNumber("Enter number of elements : ");
FillArrayWithRandomNumbers(arr, arrLength);
FillArrayWithRandomNumbers(arr2, arrLength);
SumOf2Arrays(arr, arr2 , arrSum , arrLength );
}
cout << "\nArray 1 Elements : \n";
PrintArray(arr, arrLength);
cout << "\nArray 2 Elements : \n";
PrintArray(arr2, arrLength);
cout << "\nSum of array 1 and array 2
 elements : \n";
PrintArray(arrSum, arrLength);