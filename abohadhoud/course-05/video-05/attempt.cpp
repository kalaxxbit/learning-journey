#include <iostream>
#include <iomanip>
#include <string>
#include<cmath>
using namespace std;

int ReadPositiveNumber(string Text){
    int Number=0;
    cout<<Text<<endl;
    cin>>Number;
    return Number;


}
void PrintDigets(int Number){
    float LastNum=0.0;
    while(Number>0.0){
        LastNum=float(Number)/10.0;
        Number=LastNum;
       
        LastNum=LastNum-float(Number);
        LastNum*=10.0;
       cout<<round(LastNum)<<endl;
       
        
    }
}
int main(int argc, char *argv[])
{
    
    PrintDigets( ReadPositiveNumber("Enter Number:")
 );
   return 0;
}