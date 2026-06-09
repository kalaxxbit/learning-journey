#include <iostream>
#include <iomanip>
#include <string>
#include<cmath>
using namespace std;
void PrintTableHeader(){
    cout<<setw(4)<<"        Mutiplication Table from 1 to 10        "<<endl;
    cout<<"        1   2   3   4   5   6   7   8   9   10"<<endl;
    for(int i=0 ;i<=45;i++){
        cout<<"_";
    }
    cout<<endl;

}
string ColumnSperator(int tablenum){
    return (to_string(tablenum)+"|");
}
void PrintMultiplicationTable(){
    PrintTableHeader();
    for(int i=1;i<=10;i++){
        cout<<setw(4)<<ColumnSperator(i);
        for(int j=1;j<=10;j++){
        cout<<setw(4)<<i*j;
    }
    cout<<endl;
    }
    cout<<endl;
}
int main(int argc, char *argv[])
{
    
    PrintMultiplicationTable();
   return 0;
}