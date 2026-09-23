
#include "../../../lib/MySmallLibrary.h"
#include "../../../lib/clsEmoloyee.h"

#include <string>

using namespace std;

int main() {
  clsEmoloyee Employee1(10, "kalax", "xbit", "kal@xxbit.com", "+0000912345678",
                        "Dev", "Programing", 5000);
  Employee1.Print();
  return 0;
}