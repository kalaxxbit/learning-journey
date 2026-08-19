#include "../../../lib/MySmallLibrary.h"
#include <iostream>
#include <string>

using namespace std;
class clsAddress {
private:
  string _Address1;
  string _Address2;
  string _POBox;
  string _ZipCode;

public:
  clsAddress(string Address1, string Address2, string POBox, string ZipCode) {
    _Address1 = Address1;
    _Address2 = Address2;
    _POBox = POBox;
    _ZipCode = ZipCode;
  }
  void PrintAddress() {
    cout << "_Address1: " << _Address1 << endl;
    cout << "_Address2: " << _Address2 << endl;
    cout << "_POBox: " << _POBox << endl;
    cout << "_ZipCode: " << _ZipCode << endl;
  }
  void SetAddress1(string Address1) { _Address1 = Address1; }
  void SetAddress2(string Address2) { _Address2 = Address2; }
  void SetPOBox(string POBox) { _POBox = POBox; }
  void SetZipCode(string ZipCode) { _ZipCode = ZipCode; }
};
int main() {
  clsAddress Address("Syria", "Raqqa", "1234", "1234");
  Address.PrintAddress();
  return 0;
}
