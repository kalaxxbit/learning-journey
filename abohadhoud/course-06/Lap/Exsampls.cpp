#include "MySmallLibrary.h"
#include <iomanip>
#include <vector>
using namespace std;
// Declaration Vs Definition
void A();
void B()
{

    cout << "IM B" << endl;
    A();
}
void A()
{
    cout << "IM A" << endl;
    B();
}
// DefAult Parameters
int MySum(int a, int b, int c = 0, int d = 0)
{
    return (a + b + c + d);
}

void PrintNumbers(int N, int M)
{
    if (N <= M)
    {
        cout << N << endl;
    }
    PrintNumbers(N + 1, M);
    // 1 + 1 = 2 | 2 + 1 = 3 | 3 + 1 = 4 ;
}

void MyFunctionStatic()
{
    // Function ءاهتناب Static عم ريغتملا ةايح يهتنت لا
    //  هئاعدتسلا ةقباسلا ةميقلا ىلع ظفاحي
    static int Number = 1; // 2
}

void Swap(int& a, int& b)
{
    int Temp = a;
    a = b;
    b = Temp;
}
void SwapVectorRandom(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        Swap(v.at(i), v.at(RandomFromTo(0, v.size() - 1)));
    }
    
}


int main(int argc, char *argv[])
{
    // B(); //Function B cal A and A call B etc...
    // cou<<MySum(5,5);
   /* cout << setw(9) << "N" << setw(9) << "M" << endl;
    vector <int> v{1, 2, 3, 4, 5};
    cout<<"Numbers Of Vector : ";
    for(const int& element : v)
    {
        cout << element << " ";
    }
    cout << endl;
    cout<<"Numbers Of Vector After Swap : ";
    SwapVectorRandom(v);
    for(const int& element : v)
    {
        cout << element << " ";
    }
    cout << endl;*//*
    int a = 5;
    int *p = &a;
    cout << "Value of a : " << a << endl;
    cout << "Address of a : " << &a << endl;
    cout << "Value of p : " << p << endl;
    cout << "Dereference p : " << *p << endl;*/
    int x = 10 , * p;  //  أطخ // Value  لا نزخي ميق P = Pointer p = x; p = 50;  //  حيحصلا // Address  نزخي طقف ناونع P = Pointer p = &x;  //  أطخ // ينعت لوصولا  ىلا  ةميقلا Dereference  // Value لا  متي  نيزخت ناونع  يف  ةميق *p = &x;
int a = 10;  int& x = a;  // Print Address  cout << &a << endl;  cout << &x << endl;  // Print Value  cout << a << endl;  cout << x << endl;  int* p = &a;  cout << p << endl;  cout << *p << endl;
    return 0;
}
