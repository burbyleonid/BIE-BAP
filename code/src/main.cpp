#define EXT_HERE

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <string>
#include <filesystem>
#include <stdio.h>
#include <string.h>


#include "lexan.h"
#include "parser.h"
#include "tree.h"
#include "externs.h"




int main(int argc, char *argv[]) {
  using namespace externs;
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
  FILE *out = fopen("/mnt/c/Users/Leonid/Desktop/BIE-BAP/code/src/AProVE_time_out_3_min.csv", "w");
  fprintf(out, "Test name, Execution time, Result, Values\n");
  timeout = 0;
  if (argc == 1 || sscanf(argv[1], "%lf", &timeout) != 1) {
    timeout = 180;
  }

    std::string path = "/mnt/c/Users/Leonid/Desktop/BIE-BAP/code/test/AProve/";
    for (const auto & entry : std::filesystem::directory_iterator(path)){
      std::string filename = entry.path().filename().string();
      
        // if (filename.find("STC") != std::string::npos) {
        // // Skip files that contain "STC" in their name
        // continue;
        // }

      // std::cout << entry.path().string() << std::endl;

  // for (int i = 1; i < 1001; ++i) {
    // char fileName[256];

    // Math problems - https://clc-gitlab.cs.uiowa.edu:2443/SMT-LIB-benchmarks/QF_NIA/-/tree/master/20220315-MathProblems
  //  sprintf(fileName, "/mnt/c/Users/Leonid/Desktop/BIE-BAP/code/test/20220315-MathProblems/STC_%04d.smt2", i);


    MINUS_INF = -64;
    PLUS_INF = -(MINUS_INF);

    start = std::chrono::high_resolution_clock::now();

    char* cstr = new char[entry.path().string().size() + 1]; // Allocate memory for C-style string
    strcpy(cstr, entry.path().string().c_str()); 
    std:: cout << "Computing file: " << cstr << std::endl;

    std::map<std::string, int> res;
    while (!res.size() && (dduration(std::chrono::high_resolution_clock::now() - start)).count() < timeout) {
      if(!initParser(cstr)) {
        std::cout << "Error creating the syntax analyzer." << std::endl;
        return 1;
      }
      res = Program();

      MINUS_INF *= 2;
      PLUS_INF *= 2;
      std::cout << "DEBUG:: Min = " << MINUS_INF << ", Max = " << PLUS_INF << std::endl;
    }
    //    std::cout << "End. " << (tmp != nullptr) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end - start;
 
    // char testName[100];

    // sprintf(testName, "/20220315-MathProblems/STC_%04d.smt2", i);
    std::cout << "Test name: " << cstr << ", Execution time: " << elapsed_time.count() << " seconds." << std::endl;


  
    fprintf(out, "%s, %lf, ", cstr, elapsed_time.count());
    if (res.size()) {
      fprintf(out, "SAT, ");
      for (const auto &v : res) {
        fprintf(out, "%s = %d ", v.first.data(), v.second);
               std::cout << v.first << " = " << v.second << std::endl;
      }
      fprintf(out,"\n");
    } else {
      fprintf(out, "Not SAT\n");
    }
    std::fflush(out);
    delete[] cstr;
  }

  fclose(out);
#endif
}
