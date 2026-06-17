
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
  short pos = S.find(OldWord);
  while (pos != std::string::npos) {
    S = S.replace(pos, OldWord.length(), NewWord);
    pos = S.find(OldWord);
  }
  return S;
}
int main() {
  string S12 = "Welcome to Jordan , Jordan is a nice country";
  string StringToReplace = "Jordan";
  string ReplaceTo = "USA";
  cout << "\nOrigial String\n" << S12;
  cout << "\n\nString After Replace:";
  cout << "\n" << ReplaceWordsInStrings(S12, StringToReplace, ReplaceTo);
}