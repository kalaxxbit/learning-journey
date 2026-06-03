#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main(int argc, char *argv[]){
    int Size=0;
    cout <<"Enter the size of item's: ";
    cin >> Size;
    float *ptr=new float[Size];
    for (int i=0;i<Size;i++){
        cout<<"Item ["<<i+1<<"]"<<endl;
        cin>>*(ptr+i);
    }
    for (int i=0;i<Size;i++){
        cout<<"Item="<<*(ptr+i)<<endl;
   
    }
      
    return 0;
}