#include "../../../lib/MySmallLibrary.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
enum eMainMenue {
  enQuickWithDraw = 1,
  enNormalWithDraw,
  enDeposit,
  enCheckBalance
};
struct sClient {
  string AccountNumber;
  string PinCode;
  string Name;
  string Phone;
  double AccountBalance;
  bool MarkForDelete = false;
};
const string ClientsFileName = "abohadhoud/lib/Clients.txt";
sClient CurrentClint;
void ShowMainMenue();
void ClearScreen() { system("clear"); }
vector<string> SplitString(string S1, string Delim) {
  vector<string> vString;
  short pos = 0;
  string sWord; // define a string variable
  // use find() function to get the position of the delimiters
  while ((pos = S1.find(Delim)) != std::string::npos) {
    sWord = S1.substr(0, pos); // store the word
    if (sWord != "") {
      vString.push_back(sWord);
    }
    S1.erase(0, pos + Delim.length()); /* erase() until
    positon and move to next word. */
  }
  if (S1 != "") {
    vString.push_back(S1); // it adds last word of the string.
  }
  return vString;
}
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
  sClient Client;
  vector<string> vClientData;
  vClientData = SplitString(Line, Seperator);
  Client.AccountNumber = vClientData[0];
  Client.PinCode = vClientData[1];
  Client.Name = vClientData[2];
  Client.Phone = vClientData[3];
  Client.AccountBalance = stod(vClientData[4]); // cast string to

  return Client;
}
vector<sClient> LoadCleintsDataFromFile(string FileName) {
  vector<sClient> vClients;
  fstream MyFile;
  MyFile.open(FileName, ios::in); // read Mode
  if (MyFile.is_open()) {
    string Line;
    sClient Client;
    while (getline(MyFile, Line)) {
      Client = ConvertLinetoRecord(Line);
      vClients.push_back(Client);
    }
    MyFile.close();
  }
  return vClients;
}
bool FindUserByUsernameAndPassword(string UserName, string Password,
                                   sClient &Client) {
  vector<sClient> ClientsList = LoadCleintsDataFromFile(ClientsFileName);
  for (sClient C : ClientsList) {
    if (C.PinCode == Password && C.AccountNumber == UserName) {
      Client = C;
      return true;
    }
  }
  return false;
}
bool LoadUserInfo(string UserName, string Password) {
  if (FindUserByUsernameAndPassword(UserName, Password, CurrentClint)) {
    return true;
  } else {
    return false;
  }
}

short ReadMainMenueOption() {
  cout << "Choose what do you want to do? [1 to 5]? ";
  short Choice = 0;
  cin >> Choice;
  return Choice;
}
void GoBackToMainMenue() {
  ClearScreen();
  ShowMainMenue();
}

void ShowQuickWithDrawScreen() {
  cout << setw(4) << "[1] 20\t[2] 50" << endl;
  cout << setw(4) << "[3] 100\t[4] 200";
  cout << setw(4) << "[5] 100\t[6] 200";
}
void PerfromMainMenueOption(eMainMenue MainMenueOption) {
  switch (MainMenueOption) {
  case enQuickWithDraw:
    ClearScreen();
    ShowQuickWithDrawScreen();
    GoBackToMainMenue();
    break;
  }
}
void ShowMainMenue() {
  ClearScreen();
  cout << "===========================================\n";
  cout << "\t\t Main Menue Screen\n";
  cout << "===========================================\n";

  cout << "\t[1] Quick Withdraw.\n";
  cout << "\t[2] Normal Withdraw.\n";
  cout << "\t[3] Deposit.\n";
  cout << "\t[4] Check Balance.\n";
  cout << "\t[5] Logout.\n";
  cout << "===========================================\n";
  PerfromMainMenueOption(eMainMenue(ReadMainMenueOption()));
}
void Login() {
  string UserName, Password;
  bool LoginFaild = false;

  do {
    ClearScreen();
    if (LoginFaild) {
      cout << "Invliad UserName/Password" << endl;
    }
    cout << "Login Screen" << endl;
    cout << "Enter UserName" << endl;
    cin >> UserName;
    cout << "Enter Password" << endl;
    cin >> Password;
    LoginFaild = !LoadUserInfo(UserName, Password);
  } while (LoginFaild);
  ShowMainMenue();
}
int main() {
  Login();
  return 0;
}
