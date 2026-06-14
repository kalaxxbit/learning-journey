
#include <iostream>
#include <string>

#include <vector>

using namespace std;

string ReadText(string message) {
  string Text;
  cout << message;
  getline(cin, Text);
  return Text;
}

vector<string> SplitEachWordInVector(string &S) {
  vector<string> vWords;
  short pos = 0;
  string delim = " ";
  string sWord;

  while ((pos = S.find(delim)) != std::string::npos) {
    sWord = S.substr(0, pos);
    if (sWord != "") {
      vWords.push_back(sWord);
    }
    S.erase(0, pos + delim.length());
  }
  if (S != "") {
    vWords.push_back(S);
  }
  return vWords;
}
void PrintStringVector(vector<string> V) {
  for (string &c : V) {
    cout << c << endl;
  }
}
int main() {
  string Word = ReadText("? Pleas Enter your string: ");
  vector<string> vWords = SplitEachWordInVector(Word);
  cout << "Tokens " << vWords.size() << endl;
  PrintStringVector(vWords);
  return 0;
}