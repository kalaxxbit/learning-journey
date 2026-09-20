#include <iostream>
#include <string>

using namespace std;

class clsA {
  struct stAddress {
    string FullName;
    string AddressLine1;
    string AddressLine2;
    string City;
    string Country;
  };

public:
  string FullName;
  stAddress Address;
  clsA() {
    Address.FullName = "Kalax xbit";
    Address.AddressLine1 = "Earth";
    Address.AddressLine2 = "Syria";
    Address.City = "Null";
    Address.Country = "Nullo";
  }

  void PrintAddress() {
    cout << Address.FullName << endl;     // "Kalax xbit"
    cout << Address.AddressLine1 << endl; // "Earth"
    cout << Address.AddressLine2 << endl; // "Syria
    cout << Address.City << endl;         // "Null"
    cout << Address.Country << endl;      // "Nullo"
  }
};
int main() {
  clsA A;
  A.PrintAddress();
  return 0;
}
