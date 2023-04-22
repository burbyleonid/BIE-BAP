#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>

#define MAX_LINE_LENGTH 257


// statically defined array of symbol to store individual lines
char  line[MAX_LINE_LENGTH];
int   lineNumber = 0;
char *linePointer = line;
FILE *inputFile = 0;
int extendedLine = 0;


// initialisation of input to a standard input or to a file input
// standard input is selected if fileName is NULL
int initInput(char* fileName) {
  if (inputFile != 0) {
    fclose(inputFile);
    inputFile = 0;
  }
  if (!fileName) {
    inputFile = stdin;
  } else {
    inputFile = fopen(fileName, "rt");
    if (!inputFile) {
      std::cout << "Input file " << fileName << " not found." << std::endl;
      return 0;
    }
  }
  return 1;
}


// will read single symbol from input
int getChar() {
  if (!*linePointer) {
    if (!fgets(line, MAX_LINE_LENGTH, inputFile)) return EOF;

    linePointer = line;
    lineNumber++;

    int lineLength = strlen(line);
    if (extendedLine) {
      lineNumber--;
//      printf("+    %s", line);
    } else {
//      printf("%-4d %s", lineNumber, line);
    }

    extendedLine = line[lineLength - 1] != '\n';
  }
  return *linePointer++;
}
