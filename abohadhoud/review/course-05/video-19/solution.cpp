#include#include<iostream>
<cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
// rand() int لثم همجح = 87513 الثم ريبك مقرلا نوكي ةداع يئاوشع مقر يطعي
int RandNum = rand() % (To - From + 1) + From;
// 87513 % "10" ( 10 - 1 +1 ) = 3 + 1 = 4
return RandNum; // 4
}
int main()
{
srand((unsigned)time(NULL));
// ءاعدتسا لك عم يئاوشع مقر يطعي
}
cout << RandomNumber(1, 10) << endl;
cout << RandomNumber(1, 10) << endl;
cout << RandomNumber(1, 10) << endl;