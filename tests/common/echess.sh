#!/bin/bash

TESTS=100
SIZE=700

for ((i=1; i<=TESTS; i++))
do
    ARG=$(shuf -i 1-$SIZE -n $SIZE)

    ./push_swap $ARG > ops.txt

    RESULT=$(./checker_linux $ARG < ops.txt)

    if [ "$RESULT" != "OK" ]; then
        echo "FAILED TEST $i"
        echo "$ARG"
        exit 1
    fi
done

echo "All $TESTS tests passed!"
