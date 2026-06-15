#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Problem #39
string JoinString(vector<string> vString, string Delim) {
  string S1 = "";
  for (string &s : vString) {
    S1 = S1 + s + Delim;
  }
  Write a program to join Vector of strings into a one string with separators
      : Vector after join Mohammed## #Faid## #Ali # ##Maher
}
// ريخلأا Delim فذح
return S1.substr(0, S1.length() - Delim.length());
int main() {
  // Problem #39
  vector<string> vString2 = {"Mohammed", "Faid", "Ali", "Maher"};
  cout << "\nVector after join: \n";
  cout << JoinString(vString2, "###");
}
system("pause>0");