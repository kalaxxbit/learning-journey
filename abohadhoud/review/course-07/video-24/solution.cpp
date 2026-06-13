#include #include #include < iostream>
<string><iomanip> using namespace std;
// Problem #23
string ReadString() {
  string S1 = " ";
  cout << "Pleas Enter your string ? \n";
  getline(cin, S1);
  return S1;
}
// Problem #24
string UpeerFirstLetterOfEachWord(string S1) { bool isFirstLetter = true; }
for (int i = 0; i < S1.length(); i++) {
  if (S1[i] != ' ' && isFirstLetter) {
    S1[i] = toupper(S1[i]);
  }
  isFirstLetter = (S1[i] == ' ' ? true : false);
}
return S1;
int main() {
  // Problem #24
  string S1 = ReadString();
}
cout << "\n String after Conversion : \n";
S1 = UpeerFirstLetterOfEachWord(S1);
cout << S1 << endl;
system("pause>0");