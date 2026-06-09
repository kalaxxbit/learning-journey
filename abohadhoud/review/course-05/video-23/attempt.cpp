#include <iostream>
#include <iomanip>
#include <string>
#include<cmath>
#include <cstdlib>
using namespace std;
//FastLib Start
int RandomNumbers(int From,int To){
    int RandNum=rand()%(To-From+1)+From;
    return RandNum;
}
// FastLib End
int ReadPositiveNumber(string Text){
    int Number=0;
    do{
    cout<<Text<<endl;
    cin>>Number;
    }while(Number<0);
    return Number;

}
void PrintArray(int Arr[],int To){
    
    for(int i=0;i<To;i++){
        cout<<Arr[i]<<" ";
    }
}

void fillArrayWithRandomNumbers(int Array[100]){
    for(int i=0;i<=99;i++){
        Array[i]=RandomNumbers(1,100);
    }
}
int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    int Number=ReadPositiveNumber("Enter number of elements : ");
    int Arr[100];
    fillArrayWithRandomNumbers(Arr);
    PrintArray(Arr,Number);

}