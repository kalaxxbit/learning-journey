#include <iostream>
#include <string>
using namespace std;
short ReadOneGrade(){
    short Grade;
    cout<<"Please Enter Grade: ";
    cin>>Grade;
    return Grade;
}
char CheckGrade(short Grades){
   
     if (Grades <50){
        return 'F';
    }
    else  if (Grades <=59){
        return 'E';
    }
    else  if (Grades <=69){
        return 'D';
    }
    else  if (Grades <=79){
        return 'C';
    }
    else  if (Grades <=89){
        return 'B';
    }
    else  if (Grades <=90){
        return 'A';
    }
    return 'x';
}
void PrintGrades(char Text){
    cout<<"YOUR grade is: "<<Text<<endl;
}
int main(int argc, char *argv[])
{

   PrintGrades(CheckGrade(ReadOneGrade()));
}