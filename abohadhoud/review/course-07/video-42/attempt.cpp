
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

string ReplaceWordsInStrings(string S, string OldWord, string NewWord) {
  vector<string> vString;
  string ReWords = "";
  vString = SplitEachWordInVector(S);
  for (string Word : vString) {
    ReWords += (Word == OldWord) ? NewWord : Word;
    ReWords += " ";
  }
  ReWords = ReWords.substr(0, ReWords.length() - 1);
  return ReWords;
}
int main() {
  string Word = ReadText("? Pleas Enter your string: ");

  cout << ReplaceWordsInStrings(Word, "python", "c++");
}