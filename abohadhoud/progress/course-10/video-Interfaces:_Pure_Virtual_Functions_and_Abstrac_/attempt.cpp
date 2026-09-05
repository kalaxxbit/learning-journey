#include <iostream>

using namespace std;
class clsMobile {
  virtual void Dial(string PhoneNumber) = 0;
  virtual void SendSMS(string Text) = 0;
  virtual void TakePictore() = 0;
};
class clsIphone : public clsMobile {
public:
  void Dial(string PhoneNumber) {};
  void SendSMS(string Text) {};
  void TakePictore() {};
};

class clsSamsongNote10 : public clsMobile {
public:
  void Dial(string PhoneNumber) {};
  void SendSMS(string PhoneNumber) {};
  void TakePictore();
};

int main() {
  clsIphone iPhone1;
  clsSamsongNote10 Note10;

  return 0;
}
