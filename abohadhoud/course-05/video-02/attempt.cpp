#include <iostream>
#include <iomanip>
#include <string>
#include<cmath>
using namespace std;
enum enPrimNotPrime{
    Prime,
    NotPrime
};
int ReadPositiveNumber(string Text){
    int Number=0;
    cout<<Text<<endl;
    cin>>Number;
    return Number;

}
enPrimNotPrime CheckPrime(int Number){
    int TopNumber=sqrt(Number);
    int Counter=2;
    if(Number==2){
        return Prime;
    }
    do{
        if(Number%Counter==0){
            return NotPrime;
        }
        Counter++;
    }while(Counter<=TopNumber);
    return Prime;
}
void PrintPrimeNumbersFrom1ToNumber(int CountTo){
    
      for(int i=1;i<=CountTo;i++){
        if(Prime==CheckPrime(i)){
            cout<<i<<'\t';
        }
    }
}
int main(int argc, char *argv[])
{
    
    PrintPrimeNumbersFrom1ToNumber( ReadPositiveNumber("Count Prime Number From 1 To:")
 );
   return 0;
}