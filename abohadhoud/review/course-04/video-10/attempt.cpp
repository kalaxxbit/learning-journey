#include <iostream>
#include <string>
using namespace std;
short ReadOneGrade(){
    short Grade;
    cout<<"Please Enter Grade: ";
    cin>>Grade;
    return Grade;
}

void FillReadGradesInArray(short *Array){
    
    for (int i=0;i<=2;i++){
          cout<<"Grade-"<<i+1<<endl;
       Array[i]=ReadOneGrade();
    }
 
}
short SumThreeGrades(short *Grades){
    return (Grades[0]+Grades[1]+Grades[2])/3;
}
void PrintGrades(short Text){
    cout<<Text<<endl;
}
int main(int argc, char *argv[])
{
    short Grades[3];
    FillReadGradesInArray(Grades);
   PrintGrades(SumThreeGrades(Grades));
}