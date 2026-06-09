#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: ./scripts/new_review.sh <course-number> <video-number>"
    exit 1
fi

mkdir -p abohadhoud/review/course-$1/video-$2
cd abohadhoud/review/course-$1/video-$2

for file in attempt.cpp solution.cpp
do
cat > "$file" << 'EOF'
#include <iostream>
#include "../../../lib/MySmallLibrary.h"

using namespace std;

int main()
{

    return 0;
}
EOF
done

touch problem.md notes.md

echo "Created: abohadhoud/review/course-$1/video-$2"