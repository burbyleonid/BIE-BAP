#!/bin/bash

# Define variables for the input directory and timeout value
INPUT_DIR="../test/AProVE/"
TIMEOUT=180

OUTPUT_FILE_NAME="AProVE_results_original_cvc5_time_out_3_min.csv"

# Write the CSV header to the output file
echo "Test name,Execution time,Result" > $OUTPUT_FILE_NAME

# Loop over the test files and run each one
for INPUT_FILE in $(ls $INPUT_DIR/*.smt2); do
    # Get the file name without the directory path
    FILE_NAME=$(basename "$INPUT_FILE")

    # Run the test command and measure the execution time
    start=$(date +%s.%N)
    RESULT=$(timeout $TIMEOUT ./cvc5-Linux "$INPUT_FILE" 2>&1)
    status=$?
    end=$(date +%s.%N)
    runtime=$(echo "$end - $start" | bc)

    if [[ $status -eq 0 ]]; then
        echo "$FILE_NAME,$runtime,$RESULT" >> $OUTPUT_FILE_NAME
    else
        echo "$FILE_NAME,$runtime,$RESULT" >> $OUTPUT_FILE_NAME
    fi

    # Display the progress in the terminal
    echo "Test $FILE_NAME completed"
done
