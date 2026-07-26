#include "../../../lib/MySmallLibrary.h"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
enum eMainMenue {
  enQuickWithDraw = 1,
  enNormalWithDraw,
  enDeposit,
  enCheckBalance,
  enLogout
};
struct sClient {
  string AccountNumber;
  string PinCode;
  string Name;
  string Phone;
  double AccountBalance;
  bool MarkForDelete = false;
};
const string ClientsFileName = "../../../lib/Clients.txt";
sClient CurrentClint;
void Login() ;
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

string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
  string stClientRecord = "";
  stClientRecord += Client.AccountNumber + Seperator;
  stClientRecord += Client.PinCode + Seperator;
  stClientRecord += Client.Name + Seperator;
  stClientRecord += Client.Phone + Seperator;
  stClientRecord += to_string(Client.AccountBalance);
  return stClientRecord;
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

vector<sClient> SaveCleintsDataToFile(string FileName,
                                      vector<sClient> vClients) {
  fstream MyFile;
  MyFile.open(FileName, ios::out); // overwrite
  string DataLine;
  if (MyFile.is_open()) {
    for (sClient C : vClients) {
      if (C.MarkForDelete == false) {
        // we only write records that are not marked for
        DataLine = ConvertRecordToLine(C);
        MyFile << DataLine << endl;
      }
    }
    MyFile.close();
  }
  return vClients;
}
void PauseSystem() {

  cout << "Press Any Key To go back to Main Menu";

  // Clear any leftover characters (like newlines) still in the input buffer
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // Wait for the user to press Enter
  cin.get();
}
void SaveChanges() {
  vector<sClient> ClientsList = LoadCleintsDataFromFile(ClientsFileName);
  for (sClient &C : ClientsList) {
    if (C.AccountNumber == CurrentClint.AccountNumber) {
      C = CurrentClint;
    }
  }
  SaveCleintsDataToFile(ClientsFileName, ClientsList);
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

short ReadQuickWithDrawOption() {
  cout << "Choose what to withdraw from [1] to [8] ? ";
  short Choice = 0;
  cin >> Choice;
  return Choice;
}
void PrinBalance() {
  cout << "\nYour Balance Is : " << CurrentClint.AccountBalance << endl;
}
short ReadMainMenueOption() {
  cout << "Choose what do you want to do? [1 to 9]? ";
  short Choice = 0;
  cin >> Choice;
  return Choice;
}
void GoBackToMainMenue() {
  ClearScreen();
  ShowMainMenue();
}
bool WithDrawFromClient(int HowMuchMouny) {

  if (HowMuchMouny > CurrentClint.AccountBalance) {
    cout << "The amount exceeds your balance , make another choice" << endl;
    return false;
  }
  char ans = 'N';
  cout << "Are You Sure To Make This Transaction ? N/y : ";
  cin >> ans;
  if (toupper(ans) != 'Y') {
    return false;
  }
  CurrentClint.AccountBalance -= HowMuchMouny;
  return true;
}
bool PerfromQuickWithDrawOption(short Choice) {
  switch (Choice) {
  case 1:
    return WithDrawFromClient(20);

  case 2:
    return WithDrawFromClient(50);

  case 3:
    return WithDrawFromClient(100);

  case 4:
    return WithDrawFromClient(200);

  case 5:
    return WithDrawFromClient(400);

  case 6:
    return WithDrawFromClient(600);

  case 7:
    return WithDrawFromClient(800);

  case 8:
    return WithDrawFromClient(1000);
    
  
  }
  GoBackToMainMenue();
  return false;
}




bool PerfromNormalWithdrawOption(short Amount) {
    return WithDrawFromClient(Amount);


}
bool PerfromDepositOption(short Amount) {
    return WithDrawFromClient(Amount*-1);


}

void ShowCheckBalanceScreen() {
  string line = "======================";
  cout << setw(4) << line << endl;
  cout << setw(4) << "\tCheck Balance Screen " << endl;
  cout << setw(4) << line << endl;
  PrinBalance();

  PauseSystem();
}
 
short ReadDepositOption() {
  cout << "Please Enter Positive Amount To Deposit: ";
  short Choice = 0;
  cin >> Choice;
  return Choice;
}


short ReadNormalWithdrawOption() {
  short Choice = 0;
  do{
  cout << " Enter An Amount multiple of 5s: ";
  
  cin >> Choice;
  }while(Choice %5!=0);
  return Choice;
}
void ShowDepositScreen (){
	
	string line = "======================";
  cout << setw(4) << line << endl;
  cout << setw(4) << "\tDeposit Screen " << endl;
  cout << setw(4) << line << endl;
  PrinBalance();

  if (PerfromDepositOption(ReadDepositOption())) {
    SaveChanges();
    cout << "\nDone Successfully , New Balance Is: "
         << CurrentClint.AccountBalance << endl;
  }
  PauseSystem();
}





void NormalWithDrawScreen() {
  string line = "======================";
  cout << setw(4) << line << endl;
  cout << setw(4) << "\tNormal Withdraw Screen " << endl;
  cout << setw(4) << line << endl;
  PrinBalance();

  if (PerfromNormalWithdrawOption(ReadNormalWithdrawOption())) {
    SaveChanges();
    cout << "\nDone Successfully , New Balance Is: "
         << CurrentClint.AccountBalance << endl;
  }
  PauseSystem();
}
void ShowQuickWithDrawScreen() {
  string line = "======================";
  cout << setw(4) << line << endl;
  cout << setw(4) << "\tQuick Withdraw " << endl;
  cout << setw(4) << line << endl;
  cout << setw(4) << "[1] 20\t[2] 50" << endl;
  cout << setw(4) << "[3] 100\t[4] 200" << endl;
  cout << setw(4) << "[5] 400\t[6] 600" << endl;
  cout << setw(4) << "[7] 800\t[8] 1000" << endl;
  cout << setw(4) << "[9] Exit" << endl;
  cout << setw(4) << line << endl;
  PrinBalance();

  if (PerfromQuickWithDrawOption(ReadQuickWithDrawOption())) {
    SaveChanges();
    cout << "\nDone Successfully , New Balance Is: "
         << CurrentClint.AccountBalance << endl;
  }
  PauseSystem();
}
void PerfromMainMenueOption(eMainMenue MainMenueOption) {
  
  
  switch (MainMenueOption) {
  case enQuickWithDraw:
    ClearScreen();
    ShowQuickWithDrawScreen();
    GoBackToMainMenue();
    break;
    
    
    case enNormalWithDraw:
    ClearScreen();
    NormalWithDrawScreen();
    GoBackToMainMenue();
    break;
    case enDeposit:
    ClearScreen();
    ShowDepositScreen();
    GoBackToMainMenue();
    break;
    
    case enCheckBalance:
    ClearScreen();
    ShowCheckBalanceScreen();
    GoBackToMainMenue();
    break;
    case enLogout:
    ClearScreen();
    Login();
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
