#include<iostream>
using namespace std;
void PrintTableHeader()
{
// طخلاو ةيولعلا ماقرلأاو لودجلا ناونع ةعابط
cout << "\n\n\t\t\t Multipliaction Table From 1 to 10\n\n";
cout << "\t";
for (int i = 1; i <= 10; i++)
{
cout << i << "\t"; // Print ( 1
 2
 3 ...)
}
cout <<
"\n_______________________________________________________________________
____________\n";
}
string ColumnSperator(int i)
{
// برضلا لودجو ةيدومعلا ماقرلأا نيب يذلا "|" لصافلا ةعابط
if (i < 10) // لصافلا "|" عم مقرلا دعب تاغارفلا ةعابطل
return"
 |"; // تافاسم 3 عبطا 10 نم رغصأ مقرلا
else
return" |"; // نيتفاسم عبطا 9 نم ربكأ مقرلا
}
void PrintMultiplicationTable()
{
// لودجلا ناونع ءاعدتسا
PrintTableHeader();
for (int i = 1; i <= 10; i++) // رطسلأل
{
// راركت لك عم "|" لصافلا ءاعدتسا عم 10 ىلا 1 نم ةيدومعلا ماقرلأل راركتلا ةقلح ةعابط
cout << " " << i << ColumnSperator(i) << "\t"; // Print ( 1
 |
 )
// برضلا لودج ةعابطل ةديدج راركت ةقلح ىلا لوخدلا مث
for (int j = 1; j <= 10; j++) // فصلل
{
cout << j * i << "\t"; // Print ( 1
 | 1
 2 .... )
}
cout << endl;
}
}
int main()
{
PrintMultiplicationTable();
}