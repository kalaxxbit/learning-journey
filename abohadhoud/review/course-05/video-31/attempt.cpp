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
void Swap(int &A,int &B){
    int Temp=A;
    A=B;
    B=Temp;
}
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
    cout<<endl;
}

void fillArrayWithRandomNumbers(int Array[100]){
    for(int i=0;i<=99;i++){
        Array[i]=RandomNumbers(1,100);
    }
}
void SumNumOfArray(int Arr[100],int ArrTow[100],int SumArr[100],int ArrLength){
    
    for (int i=0;i<ArrLength;i++){
     
            SumArr[i]=Arr[i]+ArrTow[i];
     
    }
   
}
void fillArrayWithNumbersFromTo(int Array[100],int To){
    for(int i=0;i<To;i++){
        Array[i]=i+1;
    }
}
void ShufflArray(int Array[100],int To){
      for(int i=0;i<To;i++){
        Swap(Array[i],Array[RandomNumbers(1,To-1)]);
    }
}
int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    int Number=ReadPositiveNumber("Enter number of elements : ");


    int Arr[100];
    fillArrayWithNumbersFromTo(Arr,Number);
    PrintArray(Arr,Number);
    ShufflArray(Arr,Number);
    PrintArray(Arr,Number);


}