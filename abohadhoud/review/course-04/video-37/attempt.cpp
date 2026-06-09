#include <iostream>
#include <string>
using namespace std;
float ReadNUmber(string Text){
    float Number;
    cout <<Text<<endl;
    cin >> Number;
    return Number;
}
float SumMultiNumbers(){
    float Temp=0;
    float Sum=0;
    short Counter=0;
    do{
        Sum+=Temp;
        Counter++;
        Temp=ReadNUmber("Enter a number-"+to_string(Counter));

    }while(Temp != -99);
    return Sum;
}

int main(int argc, char *argv[])
{

    float Sum=SumMultiNumbers();
    cout <<"Totoal Sum Is: "<<Sum;
}