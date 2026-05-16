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
bool CheckPassword(){
    int Password=1234;
    int InputPassword=0;
    for(int i=2;i>=0;i--){
        InputPassword=ReadpostiveNUmber("Enter Password: ");
        if(Password==InputPassword){
            cout<<"accses granted"<<endl;
            return 1;
        }
        cout<<"Worng Password "<<i<<" Times left"<<endl;
    }
    return 0;
}
int main(int argc, char *argv[])
{
    if(CheckPassword()){
        cout<<"you have 515M dollars";
    }else{cout<<"you have been blocked";}
}