#!/bin/bash

# Define variables for the input directory and timeout value
INPUT_DIR="../test/20220315-MathProblems/"
TIMEOUT=180

FILE_NAME="results_original_cvc5_time_out_3_min.csv"

# Write the CSV header to the output file
# echo "Test name,Execution time,Result" > $FILE_NAME

# Loop over the test files and run each one
for i in {751..1000}; do
    # Define the input file path
    INPUT_FILE="$INPUT_DIR/STC_$(printf "%04d" $i).smt2"

    # Run the test command and measure the execution time
    start=$(date +%s.%N)
    RESULT=$(timeout $TIMEOUT ./cvc5-Linux "$INPUT_FILE" 2>&1)
    status=$?
    end=$(date +%s.%N)
    runtime=$(echo "$end - $start" | bc)

    if [[ $status -eq 0 ]]; then
        echo "STC_$(printf "%04d" $i).smt2,$runtime,$RESULT" >> $FILE_NAME
    else
        echo "STC_$(printf "%04d" $i).smt2,$runtime,$RESULT" >> $FILE_NAME
    fi

    # Display the progress in the terminal
    echo "Test $i completed"
done

