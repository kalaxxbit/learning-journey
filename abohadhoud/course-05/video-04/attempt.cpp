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
void PrintPerfectNumberFrom1ToNum(int Number){
    cout<<"Print Perfect Number From 1 To "<<Number<<endl;
    for(int i=1;i<=Number;i++){
    if(CheckPerfect(i)){
        cout<<i<<'\t';
        }
    }
    cout<<endl;
}
int main(int argc, char *argv[])
{
    
    PrintPerfectNumberFrom1ToNum( ReadPositiveNumber("Enter Number:")
 );
   return 0;
}