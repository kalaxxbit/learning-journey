#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main(int argc, char *argv[]){
   vector <int> Num {1,5,3,9,4,5};
   for (const int & i : Num){
    cout << i<<endl;
   }
    return 0;
}