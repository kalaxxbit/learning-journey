#include <iomanip>
#include <iostream>
using namespace std;
int RandomNumber(int From, int To) {
  // Function to generate a random number
  int randNum = rand() % (To - From + 1) + From;
}
return randNum;
// Problem #1
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {}
for (short i = 0; i < Rows; i++) {
  for (short j = 0; j < Cols; j++) {
    arr[i][j] = RandomNumber(1, 100);
  }
}
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols; j++) {
    }
    cout << setw(3) << arr[i][j]
         << "
        cout
         << "\n";
  }
}
// Problem #4
int ColSum(int arr[3][3], short Rows, short ColNumber) {
  // دومعلا رصانع عمج
  int Sum = 0;
}
for (short i = 0; i <= Rows - 1; i++) {
  Sum += arr[i][ColNumber];
}
return Sum;
Write a program to fill a 3 * 3 matrix with random numbers,
    then print Col sum
        ? The following is a 3x3 random
        : matrix 72 59 68 11 72 9 72 47 53 The following are the sum of
    : each Col in the matrix Col 1 Sum = 130 Col 2 Sum = 178 Col 3 Sum = 155 ";
      6 void
      PrintEachColSum(int arr[3][3], short Rows, short Cols) {
  // دومع لك عومجم ةعابط
  cout << "\nThe following are the sum of each Col in the matrix : \n";
  for (short j = 0; j < Cols; j++) {
    cout << " Col " << j + 1 << " Sum = " << ColSum(arr, Rows, j) << endl;
  }
}
int main() {
  // ءاعدتسا لك عم فلتخم يئاوشع مقر
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  // Problem #1
  // ]ةدمعلأل ددعل ةيناثلا [ ] فوفصلا ددعل ىلولأا[ Matrix ىمست arr[3][3]
  // Variables
  9 = 3 * 3 = arr[3][3] int arr[3][3];
  FillMatrixWithRandomNumbers(arr, 3, 3);
  cout << "\n The following is a 3x3 random matrix:\n";
  PrintMatrix(arr, 3, 3);
  // Problem #4
  PrintEachColSum(arr, 3, 3);
  system("pause>0");
}