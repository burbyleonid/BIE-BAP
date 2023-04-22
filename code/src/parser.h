#ifndef _Parser_
#define _Parser_
#include "tree.h"

Node *Expression(void);
int initParser(char*);

std::map<std::string, int> Program();
#endif
