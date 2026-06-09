#include "../../lib/MySmallLibrary.h"

using namespace std;

void FillArrayWithRandomNumbders(int Arr[100], int ArrLength) {
  for (int i = 0; i < ArrLength; i++) {
    Arr[i] = RandomFromTo(1, 100);
  }
}

void Fill2DArrayWithRandomNumbders(int Arr[10][10], int ArrLength) {
  for (int i = 0; i < ArrLength; i++) {
    for (int j = 0; j < ArrLength; j++) {
      FillArrayWithRandomNumbders(Arr[i], ArrLength);
    }
  }
}

void PrintArray(int Arr[100], int ArrLength) {
  for (int i = 0; i < ArrLength; i++) {
    cout << '\t' << Arr[i];
  }
}
void Print2DArray(int Arr[10][10], int ArrLength) {
  for (int i = 0; i < ArrLength; i++) {

    PrintArray(Arr[i], ArrLength);
    cout << endl;
  }
}

int SumOfArray(int Arr[100], int ArrLength) {
  int Sum = 0;
  for (int i = 0; i < ArrLength; i++) {
    Sum += Arr[i];
  }
  return Sum;
}
void PrintSumOfArrayRows(int Arr[10][10], int ArrLength) {
  for (int i = 0; i < ArrLength; i++) {

    cout << "Row " << i + 1 << " Sum = " << SumOfArray(Arr[i], ArrLength);
    cout << endl;
  }
}

int main() {
  int ArrLength = 3;
  int Arr[10][10];
  Fill2DArrayWithRandomNumbders(Arr, ArrLength);
  Print2DArray(Arr, ArrLength);
  PrintSumOfArrayRows(Arr, ArrLength);
  return 0;
}
