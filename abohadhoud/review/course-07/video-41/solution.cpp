
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

string ReverseWordsInStrings(string S) {
  vector<string> vString;
  string RevWords = "";
  vString = SplitEachWordInVector(S);
  vector<string>::iterator iter = vString.end();
  while (iter != vString.begin()) {
    --iter;
    RevWords += *iter + " ";
  }
  RevWords = RevWords.substr(0, RevWords.length() - 1);
  return RevWords;
}
int main() {
  string Word = ReadText("? Pleas Enter your string: ");
  cout << "String After Reversi: " << endl;
  cout << ReverseWordsInStrings(Word);
}