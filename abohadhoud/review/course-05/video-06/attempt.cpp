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
void PrintSumOfDigets(int Number){
    float LastNum=0.0;
    int SumOfDiget=0;
    while(Number>0.0){
        LastNum=Number%10;
        Number=Number/10;
       SumOfDiget+=round(LastNum);
       
        
    }
    cout<<"Sum of Digits: "<<SumOfDiget<<endl;
}
int main(int argc, char *argv[])
{
    
    PrintSumOfDigets( ReadPositiveNumber("Enter Number:")
 );
   return 0;
}