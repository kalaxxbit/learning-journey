#include <iostream>

using namespace std;
class clsCalcator {
private:
  enum _enOprationType {
    _Add = 0,
    _Subtract,
    _Divide,
    _Multiply,
    _Clear,
    _PrintResult
  };

  float _Result = 0.0;
  float _InputNUmber = 0.0;
  const string _LastOprationName[5] = {"Adding", "Subtracting", "Divideing",
                                       "Multiplying", "Clear"};
  short _LastOpration = _enOprationType::_Clear;

public:
  void PrintResult() {
    cout << "Result After " << _LastOprationName[_LastOpration] << " "
         << _InputNUmber << " Is : " << _Result << endl;
  }
  void Clear() {
    _Result = 0;
    _LastOpration = _enOprationType::_Clear;
    _InputNUmber = 0;
  }
  void Add(float Number = 0.0) {
    _InputNUmber = Number;
    _Result += Number;

    _LastOpration = _enOprationType::_Add;
  }
  void Subtract(float Number = 0.0) {
    _Result -= Number;
    _LastOpration = _enOprationType::_Subtract;
  }
  void Divide(float Number = 1.0) {

    if (Number == 0) {

      Number = 1;
    }
    _Result /= Number;
    _InputNUmber = Number;

    _LastOpration = _enOprationType::_Divide;
  }
  void Multiply(float Number = 0.0) {
    _InputNUmber = Number;
    _Result *= Number;
    _LastOpration = _enOprationType::_Multiply;
  }
};
int main() {
  clsCalcator Calcator;
  Calcator.Clear();
  Calcator.Add(5);
  Calcator.PrintResult();
  Calcator.Clear();
  Calcator.PrintResult();
  Calcator.Multiply(5);
  Calcator.PrintResult();
  Calcator.Add(5);
  Calcator.PrintResult();
  Calcator.Divide(2);
  Calcator.PrintResult();

  return 0;
}
