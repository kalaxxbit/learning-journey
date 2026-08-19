#include "../../../lib/MySmallLibrary.h"
#include <iostream>
#include <string>

using namespace std;
class clsTheFirstAndLastWord {
private:
  string _TheFirstWord;
  string *_TheSecretMessageAddres;
  string _TheLastWord;

public:
  clsTheFirstAndLastWord(string TheLastWord, string *SecretMessageAddres) {
    _TheSecretMessageAddres = SecretMessageAddres;
    SetTheFirstWord("koko");
    SetTheLastWord(TheLastWord);
  }
  void SetTheFirstWord(string Word) { _TheFirstWord = Word; }
  void SetTheLastWord(string Word) { _TheLastWord = Word; }
  ~clsTheFirstAndLastWord() {
    cout << "He First Word Was : " << _TheFirstWord << endl;
    *_TheSecretMessageAddres = "This Is a Secret Msg If You Can See It That "
                               "Mean The Memory Cleard Succfly...";

    cout << "And He Last Word Was : " << _TheLastWord << endl;
  }
};

void CallTheClassAndGiveItAddresOfMsg(string &Msg) {
  clsTheFirstAndLastWord TheObject("Peace To You", &Msg);
}
int main() {
  string Msg;
  CallTheClassAndGiveItAddresOfMsg(Msg);
  cout << Msg << endl;
}
