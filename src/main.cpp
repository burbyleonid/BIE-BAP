#include "lexan.h"
#include "parser.h"
#include "tree.h"

#include <stdio.h>
#include <chrono>
#include <iostream>


int main(int argc, char *argv[]) {

    auto start = std::chrono::high_resolution_clock::now();
    char *fileName;
    Node *res;
     std::cout << "Evaluation of an expression by traversing an abstract syntax tree." << std::endl;
    if (argc == 1) {
        std::cout << "Input from keyboard, write the source code terminated by a dot." << std::endl;
        fileName = NULL;
    } else {
        fileName = argv[1];
        std::cout << "Input file : " << fileName << std::endl;
    }
    if(!initParser(fileName)) {
        std::cout << "Error creating the syntax analyzer." << std::endl;
        return 1;
    }

    Node* tmp = Program();
    std::cout << "End. " << (tmp != nullptr) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end - start;
    std::cout << "\nExecution time: " << elapsed_time.count() << " seconds." << std::endl;

}
