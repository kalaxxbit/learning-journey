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
void PrintInvertedLetterPattern(int Number){
    for (int i=1; i<=Number;i++){
        for(int j=1;j<=i;j++){
            cout<<char(64+i);
        }
        cout<<"\t";
    }
}
int main(int argc, char *argv[])
{
    
    PrintInvertedLetterPattern( ReadPositiveNumber("Enter Number:")
 );
   return 0;
}