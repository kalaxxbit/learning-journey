#include <cstdlib>
#include <iostream>
using namespace std;
int RandomNumber(int From, int To) {
  // Function to generate a random number
  int randNum = rand() % (To - From + 1) + From;
  return randNum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {

  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols; j++) {
      arr[i][j] = RandomNumber(1, 100);
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

int FindMinNumInMatrix(int arr[3][3], short Row, int Cols) {
  int MinNum = arr[0][0];
  for (short i = 0; i < Row; i++) {
    for (short j = 0; j < Cols; j++) {
      MinNum = (arr[i][j] < MinNum) ? arr[i][j] : MinNum;
    }
  }
  return MinNum;
}

int FindMaxNumInMatrix(int arr[3][3], short Row, int Cols) {
  int MaxNum = arr[0][0];
  for (short i = 0; i < Row; i++) {
    for (short j = 0; j < Cols; j++) {
      MaxNum = (arr[i][j] > MaxNum) ? arr[i][j] : MaxNum;
    }
  }
  return MaxNum;
}

int main() {
  srand((unsigned)time(NULL));
  int Arr[3][3];
  FillMatrixWithRandomNumbers(Arr, 3, 3);
  PrintMatrix(Arr, 3, 3);
  cout << "Min Number is : " << FindMinNumInMatrix(Arr, 3, 3);
  cout << endl;
  cout << "Max Number is : " << FindMaxNumInMatrix(Arr, 3, 3);
}
