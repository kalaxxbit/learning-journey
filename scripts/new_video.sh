for file in attempt.cpp solution.cpp
do
cat > "$file" << 'EOF'
#include <iostream>
#include "../../lib/MySmallLibrary.h"

using namespace std;

int main()
{

    return 0;
}
EOF
done
