#include <cstdlib>
#include <iostream>
using namespace std;
int RandomNumber(int From, int To) {
  // Function to generate a random number
  int randNum = rand() % (To - From + 1) + From;
  return randNum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
  short Counter = 0;
  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols; j++) {
      arr[i][j] = ++Counter;
    }
  }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols; j++) {
      cout << '\t' << arr[i][j];
    }
    cout << endl;
  }
}

int ColsSum(int arr[3][3], short Row, int Cols) {
  int Sum = 0;
  for (short i = 0; i < Row; i++) {

    Sum += arr[i][Cols];
  }
  return Sum;
}

int main() {
  srand((unsigned)time(NULL));
  int Arr[3][3];
  FillMatrixWithRandomNumbers(Arr, 3, 3);
  PrintMatrix(Arr, 3, 3);
}