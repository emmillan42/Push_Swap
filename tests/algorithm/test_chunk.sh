#!/usr/bin/env bash

PROGRAM=${1:-./main_chunk}
SIZE=${2:-100}
TESTS=${3:-100}

echo "Program : $PROGRAM"
echo "Size    : $SIZE"
echo "Tests   : $TESTS"
echo

for ((i=1; i<=TESTS; i++)); do
    ARG=$(shuf -i 0-$((SIZE - 1)) -n "$SIZE")

    printf "[%3d/%3d] " "$i" "$TESTS"

    if "$PROGRAM" $ARG | grep -q "Sorted: YES"; then
        echo "OK"
    else
        echo "FAILED"
        echo
        echo "Iteration: $i"
        echo "Arguments:"
        echo "$ARG"
        exit 1
    fi
done

echo
echo "✅ All tests passed!"
