#include <iostream>
#include <ctime>
using namespace std;
int main(){
    time_t t=time(0);
    char* dt=ctime(&t);
    cout<<"local time is "<<dt<<'\n';
}