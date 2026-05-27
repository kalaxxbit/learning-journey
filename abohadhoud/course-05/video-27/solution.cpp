#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
}
int RandNum = rand() % (To - From + 1) + From;
return RandNum;
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
cout << "Enter number of elements : \n";
cin >> arrLength;
}
for (int i = 0 ; i < arrLength; i++)
arr[i] = RandomNumber(1, 100);
void PrintArray(int arr[100], int arrLength)
{
for (int i = 0; i < arrLength; i++)
cout << arr[i] << " ";
}
cout << "\n";
int SumArray(int arr[100], int arrLength)
{
int Sum = 0;
}
for (int i = 1; i < arrLength; i++)
{
Sum += arr[i];
}
return Sum;
float ArrayAverage(int arr[100] , int arrLength )
{
return (float) SumArray(arr , arrLength) / arrLength;
}
int{
main()
srand((unsigned)time(NULL));
}
int arr[100], arrLength;
FillArrayWithRandomNumbers(arr, arrLength);
cout << "\nArray Elements : ";
PrintArray(arr, arrLength);
cout << "\nAverage of all Number is : ";
cout << ArrayAverage(arr, arrLength) << endl;