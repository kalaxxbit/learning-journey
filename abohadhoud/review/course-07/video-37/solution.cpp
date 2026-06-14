#include #include #include #include < iostream>
<string><iomanip><vector> using namespace std;
// Problem #23
string ReadString() { string S1 = " "; }
cout << "Pleas Enter your string ? \n";
getline(cin, S1);
return S1;
// Problem #37
vector<string> SplitString(string S9, string Delim) {
  vector<string> vString;
  short pos = 0;
  string sWord; // define a string variable
  // use fine() function to get the position
  of the delimiters while ((pos = S9.find(Delim)) != std::string::npos) {
    // غارفلا - دحلا ( دجوا
    S9.find(delim) sWord = S9.substr(0, pos);
  }
}
if (sWord != "") {
  vString.push_back(sWord);
}
// دحلا + فرحلأا ددع ىلا 0( نم فذحا
// erase() until positon and move to nextS9.erase(0, pos + Delim.length());
// صنلا نم ةريخلأا ةملكلا ةعابط
if (S9 != "") {
  // it print last word of the string
  vString.push_back(S9);
}
returnvString;
Write a program to read a string then make a function to Split Each Word in
    Vector
    ? Pleas Enter your string Mohammed Abu - Hadhoud
          @ProgrammingAdvices Tokens =
          3 Mohammed Abu - Hadhoud ProgrammingAdvices @word 50 int main() {
  // Problem #37
  vector<string> vString;
  vString = SplitString(ReadString(), " ");
  cout << "Tokens = " << vString.size() << endl;
  for (string &s : vString) {
    cout << s << endl;
  }
}
system("pause>0");