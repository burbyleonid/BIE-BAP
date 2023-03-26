#include "lexan.h"
#include "parser.h"
#include "tree.h"

#include <stdio.h>
#include <chrono>
#include <iostream>


int main(int argc, char *argv[]) {

#if 0
  char *fileName;

  printf("Evaluation of an expression by traversing an abstract syntax tree.\n");
  if (argc == 1) {
      printf("Input from keyboard, write the source code terminated by a dot.\n");
      fileName = NULL;
  } else {
      fileName = argv[1];
      printf("Input file %s.\n", fileName);
  }
  if(!initParser(fileName)) {
      printf("Error creating the syntax analyzer.\n");
      return 0;
  }

  auto start = std::chrono::high_resolution_clock::now();
  auto res = Program();

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed_time = end - start;
  std::cout << "\nExecution time: " << elapsed_time.count() << " seconds." << std::endl;

  if (res.size()) {
    std::cout << "SAT:\n";
    for (const auto &v : res) {
      std::cout << v.first << " = " << v.second << std::endl;
    }
  } else {
    std::cout << "Not SAT:\n";
  }

#else

// TODO download https://github.com/cvc5/cvc5/releases/latest/download/cvc5-Linux for testing original cvc5

// TODO Rename to real path for output cvc file
  FILE *out = fopen("/mnt/c/Users/Leonid/Desktop/BIE-BAP-MAIN/src/results.csv", "w");
  fprintf(out, "Test name,Execution time,Result,Values\n");



  for (int i = 1; i < 1001; ++i) {
    char fileName[256];

    // Math problems - https://clc-gitlab.cs.uiowa.edu:2443/SMT-LIB-benchmarks/QF_NIA/-/tree/master/20220315-MathProblems

    // TODO Rename to real path for input STC tests
    sprintf(fileName, "/mnt/c/Users/Leonid/Desktop/BIE-BAP-MAIN/test/STC_%04d.smt2", i);
    if(!initParser(fileName)) {
      std::cout << "Error creating the syntax analyzer." << std::endl;
      return 1;
    }
    auto start = std::chrono::high_resolution_clock::now();
    auto res = Program();
    //    std::cout << "End. " << (tmp != nullptr) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end - start;
 
    char testName[100];

    sprintf(testName, "/20220315-MathProblems/STC_%04d.smt2", i);
    std::cout << "Test name:" << testName << ",Execution time:" << elapsed_time.count() << "seconds." << std::endl;

  
    fprintf(out, "%s, %lf, ", testName, elapsed_time.count());
    if (res.size()) {
      fprintf(out, "SAT,");
      for (const auto &v : res) {
        fprintf(out, "%s = %d ", v.first.data(), v.second);
               std::cout << v.first << " = " << v.second << std::endl;
      }
      fprintf(out,"\n");
    } else {
      fprintf(out, "Not SAT\n");
    }
  }

  fclose(out);
#endif
}
