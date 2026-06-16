
#include <iostream>
#include <string>

#include <utility>
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

void ReverseStringVector(vector<string> &vWords) {
  vector<string> RevWords;
  for (int i = 0; i < vWords.size(); i++) {
    RevWords.push_back(vWords[vWords.size() - 1 - i]);
  }
  vWords = RevWords;
}
// Low Memory Edition i think
void ReverseStringVectorLM(vector<string> &vWords) {
  short HalfLength = vWords.size() / 2;
  for (int i = 0; i < HalfLength; i++) {
    swap(vWords[i], vWords[vWords.size() - 1 - i]);
  }
}

int main() {
  string Word = ReadText("? Pleas Enter your string: ");
  vector<string> vWords = SplitEachWordInVector(Word);
  PrintStringVector(vWords);
  cout << "String After Reversing: " << endl;
  ReverseStringVector(vWords);
  PrintStringVector(vWords);
  return 0;
}