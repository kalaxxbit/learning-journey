#include <cstdlib>
#include <iostream>

using namespace std;

string ReadText(string message) {
  string Text;
  cout << message;
  getline(cin, Text);
  return Text;
}

void PrintFirstLetterofEachWord(string S) {
  bool IsFristChar = true;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] != ' ' && IsFristChar) {
      cout << S[i] << endl;
    }
    IsFristChar = (S[i] == ' ' ? true : false);
  }
}

int main() {
  PrintFirstLetterofEachWord(ReadText("? Pleas Enter your string: "));
  return 0;
}