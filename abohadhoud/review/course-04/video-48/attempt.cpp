#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int ReadpostiveNUmber(string Text){
    int Number;
    do{
    cout <<Text<<endl;
    cin >> Number;
    }while(Number<=0);
    return Number;
}
float GetHowMOunthYOUNeedToPay(int Mounth,int Mouny){
    return float(Mouny)/Mounth;
}
 
int main(int argc, char *argv[])
{
       int Mouny=ReadpostiveNUmber("how mouny you have; ");
       int Mounth=ReadpostiveNUmber("how Mounth you have; ");
       cout<<"you need "<<GetHowMOunthYOUNeedToPay(Mounth,Mouny)<<" to pay full monyyy"<<endl;
       
}