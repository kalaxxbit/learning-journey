#include <iostream>
#include <string>
using namespace std;
string ReadText(){
    string Text;
    getline(cin,Text);
    return Text;
}
void PrintText(string Text){
    cout<<Text<<endl;
    
}
int main(int argc, char *argv[])
{
    PrintText("Enter Your Name: ");

    PrintText(ReadText());
}
