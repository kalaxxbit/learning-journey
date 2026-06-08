#include <iostream>
#include <string>
#include <termios.h>
#include <fstream>
#include <unistd.h>
using namespace std;

char getch()
{
	struct termios oldt, newt;
	char c;
	tcgetattr(STDIN_FILENO, &oldt);			 // الحصول على الإعدادات الحالية
	newt = oldt;							 // نسخ الإعدادات
	newt.c_lflag &= ~(ICANON | ECHO);		 // تعطيل وضع الكانون
	tcsetattr(STDIN_FILENO, TCSANOW, &newt); // تطبيق الإعدادات الجديدة
	c = getchar();							 // قراءة الحرف
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // استعادة الإعدادات الأصلية
	return c;
}

bool VaildateNumberFromTo(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

string ReadText(string message)
{
	string Text;
	cout << message;
	getline(cin, Text);
	return Text;
}
int RandomFromTo(int From, int To)
{
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
void PrintFile(string Name)
{
	string Line;
	fstream File;
	File.open(Name, ios::in);
	if (File.is_open())
	{
		while (getline(File, Line))
		{
			cout << Line << endl;
		}
		File.close();
	}
}
