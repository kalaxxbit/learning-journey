#pragma warning(disable : 4996) // ةلكشملا هذه مقرل أطخلا زواجت
#include <iostream>
#include <ctime>
int main()
{
// يلحملا تيقوتلا
time_t t = time(0);
 // get time now
// string ىلا تقولاو خيراتلا ليوحت
char* dt = ctime(&t); // convert in string from
cout << "Local date and time is : " << dt << "\n\n";
time
// شتنيرج تيقوت
tm* gmtm = gmtime(&t); // converting now to tm struct for UTC date /
// string ىلا struct نم تانايبلا ليوحت asctime(gmtm)
dt = asctime(gmtm);
cout << "UTC date and time is : " << dt << "\n\n";
return 0;
}