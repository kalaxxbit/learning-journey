#include <cctype>
#include <iostream>

using namespace std;

string ReadText(string message) {
  string Text;
  cout << message;
  getline(cin, Text);
  return Text;
}

void UpperFirstLetterofEachWord(string &S) {
  bool IsFristChar = true;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] != ' ' && IsFristChar) {
      S[i] = toupper(S[i]);
    }
    IsFristChar = (S[i] == ' ' ? true : false);
  }
}

int main() {
  string Word = ReadText("? Pleas Enter your string: ");
  UpperFirstLetterofEachWord(Word);
  cout << Word << endl;
  return 0;
}