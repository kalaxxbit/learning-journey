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
void ReadArray(int Arr[],int To){
    for(int i=0;i<To;i++){
        Arr[i]=ReadPositiveNumber("Item "+to_string(i+1)+": ");


    }
}
void PrintArray(int Arr[],int To){
    
    for(int i=0;i<To;i++){
        cout<<Arr[i]<<" ";
    }
}

int TimeRepeated(int Arr[],int To,int Number){
    int TimeRepeat=0;
    for(int i=0;i<To;i++){
        if(Arr[i]==Number){
            TimeRepeat++;
        }
    }
    return TimeRepeat;
}
int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    int Number=ReadPositiveNumber("Enter number of elements : ");
    int Arr[256];
    ReadArray(Arr,Number);
    cout<<"Original array : ";
    PrintArray(Arr,Number);
    cout<<"\n Number "<<1<<" Is repated "<<TimeRepeated(Arr,Number,1)<<" Times"<<endl;
}