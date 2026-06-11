#include <cstdlib>
#include <iostream>
#include <utility>
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

bool CheckIsMatrixPalindrome(int arr[3][3], short Rows, short Cols) {
  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols / 2; j++) {
      if (arr[i][j] != arr[i][Cols - 1 - j]) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  srand((unsigned)time(NULL));
  int Arr[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};
  // FillMatrixWithRandomNumbers(Arr, 3, 3);
  PrintMatrix(Arr, 3, 3);
  if (CheckIsMatrixPalindrome(Arr, 3, 3)) {
    cout << "YES : Matrix is .Palindrome";
  } else {
    cout << "No : Matrix is Not .Palindrome";
  }
}