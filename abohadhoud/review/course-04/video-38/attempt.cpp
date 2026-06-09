#include <iostream>
#include <string>
#include<cmath>
using namespace std;
enum PrimeNumber{Isprime ,notprime};
int ReadNUmber(string Text){
    int Number;
    cout <<Text<<endl;
    cin >> Number;
    return Number;
}
PrimeNumber IsPrimeNumber(int Number){
    int TopNum=sqrt(Number);
    if(Number >1&&0==Number%Number&&0==Number%1){
        for (;TopNum >1;TopNum--){
            if(0==Number%TopNum){
                return notprime;
            }
        }
    }
    else{return notprime;}
    return Isprime;

}
 
int main(int argc, char *argv[])
{
       int Number=ReadNUmber("Enter Number big than 1 to check is it Prime: ");
       if(IsPrimeNumber(Number)== Isprime){
        cout <<Number<<" is Prime Number"<<endl;
       }
       else{
        cout <<Number<<" is Not Prime Number"<<endl;
       }
}