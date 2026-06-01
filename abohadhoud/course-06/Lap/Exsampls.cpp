#include "MySmallLibrary.h"
using namespace std;
// Declaration Vs Definition
void A();
void B(){
    cout<<"IM B"<<endl;
    A();
}
void A(){
    cout<<"IM A"<<endl;
    B();
}
// DefAult Parameters
int MySum(int a, int b, int c = 0, int d = 0)
{
    return (a + b + c + d);
}



// رتمارابلا عون فلاتخا
double MySum(double a, double b)
{
return (a + b);
}
// رتمارابلا عون فلاتخا
int MySum(int a, int b)
{
return (a + b);
}
// رتمارابلا ددع فل
// 
// اتخا
int MySum(int a, int b , int c)
{
return (a + b + c);
}
// رتمارابلا ددع فلاتخا
int MySum(int a, int b, int c , int d)
{
return (a + b + c + d);
}


int main(int argc, char *argv[])
{
    B(); //Function B call A and A call B etc...
    //cou<<MySum(5,5);
    return 0;

}