#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: ./scripts/new_video.sh <course-number> <video-number>"
    exit 1
fi

mkdir -p abohadhoud/course-$1/video-$2
cd abohadhoud/course-$1/video-$2

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

touch problem.md notes.md

echo "Created: abohadhoud/course-$1/video-$2"
