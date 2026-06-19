#include "../../../lib/MySmallLibrary.h"
#include <iostream>

using namespace std;
bool isLeapYear(short Year) {
  if (Year % 400 == 0) {
    return true;
  } else if (Year % 100 == 0) {
    return false;
  } else if (Year % 4 == 0) {
    return true;
  } else {
    return false;
  }
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
