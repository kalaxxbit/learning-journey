#include <iostream>
#include <string>

using namespace std;

class clsPerson {
  class clsAddress {
    string _FullName;
    string _AddressLine1;
    string _AddressLine2;
    string _City;
    string _Country;

  public:
    void Print() {
      cout << "Address: " << endl;
      cout << _FullName << endl;
      cout << _AddressLine1 << endl;
      cout << _AddressLine2 << endl;
      cout << _City << endl;
      cout << _Country << endl;
    }
    void SetFullName(string FullName) {
      _FullName = FullName;
      ;
    }
    void SetAddressLine1(string AddressLine1) { _AddressLine1 = AddressLine1; }
    void SetAddressLine2(string AddressLine2) { _AddressLine2 = AddressLine2; }
    void SetCity(string City) { City = _City; }
    void SetCountry(string Country) { _Country = Country; }
  };

public:
  string FullName;
  clsAddress Address;
  clsPerson() {
    Address.SetFullName("Kalax xbit");
    Address.SetAddressLine1("Earth");
    Address.SetAddressLine2("Syria");
    Address.SetCity("Null");
    Address.SetCountry("Nullo");
  }
};
int main() {
  clsPerson Person1;
  Person1.Address.Print();
  return 0;
}
