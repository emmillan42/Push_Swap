#!/usr/bin/env bash

OUTPUT="output.txt"

echo "========================================" | tee -a "$OUTPUT"
echo "Date : $(date)" | tee -a "$OUTPUT"
echo "Input: $*" | tee -a "$OUTPUT"
echo | tee -a "$OUTPUT"

./main_chunk "$@" | tee -a "$OUTPUT"

echo | tee -a "$OUTPUT"
