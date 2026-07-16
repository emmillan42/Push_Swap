#!/bin/bash

TESTS=100
SIZE=100

for ((i=1; i<=TESTS; i++))
do
    ARG=$(shuf -i 1-$SIZE -n $SIZE)
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)

    if [ "$RESULT" != "OK" ]; then
        echo "FAILED TEST $i"
        echo "$ARG"
        exit 1
    fi
done

echo "All $TESTS tests passed!"
