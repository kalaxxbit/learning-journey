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
bool CheckPerfect(int Number){
    int SumOfNum=0;
    for(int i=1;i<Number;i++){
        if(Number%i==0){
            SumOfNum+=i;
        }
       
    }
    return (SumOfNum==Number);
}
void PrintResult(int Number){
    cout<<"Check number is perfct"<<endl;
    if(CheckPerfect(Number)){
        cout<<"Number "<<Number<<" Is Perfect"<<endl;
    }else{
        cout<<"Number "<<Number<<" Is Not Perfect"<<endl;
 
    }

}
int main(int argc, char *argv[])
{
    
    PrintResult( ReadPositiveNumber("Enter Number:")
 );
   return 0;
}