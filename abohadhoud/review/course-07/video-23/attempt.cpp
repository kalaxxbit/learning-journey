#include <cstdlib>
#include <iostream>

using namespace std;

string ReadText(string message) {
  string Text;
  cout << message;
  getline(cin, Text);
  return Text;
}

void PrintFirstLetterofEachWord(string Word) {
  short Counter = 0;
  cout << Word[0] << endl;

  while (Word[Counter] != '\0') {
    if (Word[Counter] == ' ') {
      cout << Word[Counter + 1] << endl;
    }
    Counter++;
  }
}

int main() {
  PrintFirstLetterofEachWord(ReadText("? Pleas Enter your string: "));
  return 0;
}