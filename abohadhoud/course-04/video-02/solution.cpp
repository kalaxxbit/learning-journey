#include <iostream>
#include <string>
using namespace std;
string ReadName(){
    string Name;
    cout<<"Please Enter Your Name "<<endl;
    getline(cin,Name);
    return Name;
}
void PrintName(string Name){
    cout<<"Your Name is "<<Name<<endl;
}
int main(int argc, char *argv[])
{
    PrintText(ReadName());
}
