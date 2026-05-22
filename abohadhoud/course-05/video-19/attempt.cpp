#include <iostream>
#include <iomanip>
#include <string>
#include<cmath>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){
    int RandNum=rand()%(To-From+1)+From;
    return RandNum;
}
int ReadPositiveNumber(string Text){
    int Number=0;
    cout<<Text<<endl;
    cin>>Number;
    return Number;


}
void PrintInvertedLetterPattern(){
    for (int i=1; i<=10;i++){

        cout<<RandomNumbers(1,10)<<endl;
    }
}
int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    
    PrintInvertedLetterPattern();
   return 0;
}