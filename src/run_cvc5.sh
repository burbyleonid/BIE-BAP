#!/bin/bash

# Define variables for the input directory and timeout value
INPUT_DIR="../test/20220315-MathProblems/"
TIMEOUT=60

# Write the CSV header to the output file
echo "Test name,Execution time,Result,Values" > results_origianl_cvc5.csv

# Loop over the test files and run each one
for i in {1..1000}; do
    # Define the input file path
    INPUT_FILE="$INPUT_DIR/STC_$(printf "%04d" $i).smt2"

    # Run the test command and measure the execution time
    start=$(date +%s.%N)
    timeout $TIMEOUT ./cvc5-Linux "$INPUT_FILE" &> /dev/null
    end=$(date +%s.%N)
    runtime=$(echo "$end - $start" | bc)

    # Check if the test timed out
    if [ $? -eq 124 ]; then
        echo "Test $i timed out"
        result="TIMEOUT"
        values="N/A"
    else
        # Parse the result and values from the output
        result=$(timeout $TIMEOUT ./cvc5-Linux "$INPUT_FILE" | grep "unsat\|sat\|unknown")
        values=$(timeout $TIMEOUT ./cvc5-Linux "$INPUT_FILE" | grep -A 1 "model" | tail -n 1)
    fi

    # Write the results to the output CSV file
    echo "$INPUT_FILE,$runtime,$result,$values" >> results_origianl_cvc5.csv
done
