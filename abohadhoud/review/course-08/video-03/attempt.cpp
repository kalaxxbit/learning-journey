#include "../../../lib/MySmallLibrary.h"
#include <iostream>

using namespace std;
bool isLeapYear(short Year) {

  return (Year % 400 == 0) || (!(Year % 100 == 0) && (Year % 4 == 0));
}
int ReadYear() {
  int Year = 0;
  cout << "enter year: ";
  cin >> Year;
  return Year;
}
int main() {
  int Year = ReadYear();
  if (isLeapYear(Year)) {
    cout << "Yes Year[" << Year << "] Is  a leap year" << endl;

  } else {
    cout << "No Year[" << Year << "] Is not a leap year" << endl;
  }

  return 0;
}
