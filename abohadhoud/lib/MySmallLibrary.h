#include <fstream>
#include <iostream>
#include <string>
#include <termios.h>

#include <unistd.h>
using namespace std;
// I Know Thats Bad for performc but idc now because im not reasch that level
// yet
inline char getch() {
  struct termios oldt, newt;
  char c;
  tcgetattr(STDIN_FILENO, &oldt);          // الحصول على الإعدادات الحالية
  newt = oldt;                             // نسخ الإعدادات
  newt.c_lflag &= ~(ICANON | ECHO);        // تعطيل وضع الكانون
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); // تطبيق الإعدادات الجديدة
  c = getchar();                           // قراءة الحرف
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // استعادة الإعدادات الأصلية
  return c;
}

inline bool VaildateNumberFromTo(int Number, int From, int To) {
  return (Number >= From && Number <= To);
}
inline bool isLeapYear(short Year) {

  return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

inline short NumberOfDaysInYear(short Year) { return isLeapYear(Year) + 365; }
inline short NumberOfHoursInYear(short Year) {
  return NumberOfDaysInYear(Year) * 24;
}
inline short NumberOfMinutesInYear(short Year) {
  return NumberOfHoursInYear(Year) * 60;
}
inline short NumberOfSecondsInYear(short Year) {
  return NumberOfMinutesInYear(Year) * 60;
}

inline short NumberOfDaysInAMonth(short Month, short Year) {
  if (Month < 1 || Month > 12)
    return 0;
  int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

inline string ReadText(string message) {
  string Text;
  cout << message;
  getline(cin, Text);
  return Text;
}
inline int RandomFromTo(int From, int To) {
  int Rand = rand() % (From - To + 1) + From;
  return Rand;
}
/*
char RandomLetter(enRandomType Type)
{
        switch (Type)
        {
        case CapitalLetter:
                return char(RandomFromTo(65, 90));

        case SmallLetter:
                return char(RandomFromTo(97, 122));
        case Digit:
                return (char)RandomFromTo(0, 9);

        case SpichalLetter:
                return char(RandomFromTo(33, 47));
        }
}
*/
inline void PrintFile(string Name) {
  string Line;
  fstream File;
  File.open(Name, ios::in);
  if (File.is_open()) {
    while (getline(File, Line)) {
      cout << Line << endl;
    }
    File.close();
  }
}
