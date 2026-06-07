#include <iostream>
#include <fstream>
using namespace std;
int main()
{
fstream MyFile;
// MyFile.open("هعونو .كسيد دراهلا يف نزخملا فلملا مسا", ios::out فلم ءاشنإ);
MyFile.open("MyFile.txt", ios::out); // Write Mode
}
// لمعي فلملا نأ نم دكأتلل
if (MyFile.is_open())
{
// ةشاشلا ىلع سيلو فلملا ىلع ةعابطلل
// فلملا مسا cout لدب نكل
MyFile << "Hi, this is the first line \n";
MyFile << "Hi, this is the second line \n";
MyFile << "Hi, this is the third line \n";
}
// هقلاغإ نم دبلا فلملا نم ءاهتنلاا دعب
MyFile.close();