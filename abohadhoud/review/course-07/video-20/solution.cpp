#include <iomanip>
#include <iostream>
using namespace std;
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols; j++) {
      cout << setw(3) << arr[i][j]
           << "
              ";
    }
    cout << "\n";
  }
}
Write a program to check it the matrix is Palindrome or not
    ?: Matrix 1 2 1 5 5 5
    // Problem #20
    7 3 7 bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols) {
YES:
  Matrix is for (short i = 0; i < Rows; i++) {
    .Palindrome
            // يعاد لاف فصتنملا ىلا ققحتلا لصو اذإ
            اقباس ققحملا -
        رخلآا فرطلا نم ققحتلل Cols / 2 for (short j = 0; j < Cols / 2; j++) {
      if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
        return false;
    }
  }
  return true;
}
int main() {
  int Matrix[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};
  // Problem #20
  cout << "\n Matrix :\n";
  PrintMatrix(Matrix, 3, 3);
}
if (IsPalindromeMatrix(Matrix, 3, 3))
  cout << "\n YES : Matrix is Palindrome.\n";
else
  cout << "\n No : Matrix is NOT Palindrome.\n";
system("pause>0");