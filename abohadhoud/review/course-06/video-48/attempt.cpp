#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main(int argc, char *argv[]){
   vector <int> Num {1,5,3,9,4,5};
   vector <int> ::iterator iter;
   for (iter =Num.begin();iter<Num.end();iter++){
    cout << *iter<<endl;
   }
    return 0;
}
