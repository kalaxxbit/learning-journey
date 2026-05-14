#include <iostream>
#include <string>
using namespace std;
int ReadTotalSales(){
    int Sales;
    cout<<"Please Enter Totoal Sales: ";
    cin>>Sales;
    return Sales;
}
float GetSalesPrecentages(int Sales){
   
     if (Sales >=1000000){
        return 0.01;
    }
    else  if (Sales >=500000){
        return 0.02;
    }
    else  if (Sales >=100000){
        return 0.03;
    }
    else  if (Sales >=50000){
        return 0.05;
    }
    else{return 0.0;}
}
float  CalculateTotalComission(int TotalSales){
    return TotalSales*GetSalesPrecentages(TotalSales);
}

int main(int argc, char *argv[])
{

    float Sales=ReadTotalSales();
    cout<<"YOUR Sales Precent is: "<<GetSalesPrecentages(Sales)<<endl;
    cout<<"YOUR Sales Total Precent is: "<<CalculateTotalComission(Sales)<<endl;
}