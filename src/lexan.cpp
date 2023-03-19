#include "lexan.h"
#include "input.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdexcept>

typedef enum {LETTER, NUMBER, WHITE_SPACE, PIPE_LINE, END, NO_TYPE} InputCharType;


const char *symbTable[79] = {
  "IDENT",
  "NUMB",
  "NUMBR",
  "STRING",
  "ARRAY",
  "PLUS",
  "MINUS",
  "MULTIPLY",
  "DIVIDE",
  "LESS",
  "LESS_OR_EQ",
  "GREATER",
  "GREATER_OR_EQ",
  "ASSIGN",
  "DOT",
  "SEMICOLON",
  "kwIF",
  "kwTHEN",
  "kwELSE",
  "kwFOR",
  "kwDO",
  "kwWHILE",
  "kwPROGRAM",
  "kwUSES",
  "kwCONST",
  "kwFUNCTION",
  "kwBEGIN",
  "kwEND",
  "kwPROCEDURE",
  "EOI",
  "ERR",
  "kwVAR",
  "kwAND",
  "kwDIV",
  "kwFILE",
  "kwIN",
  "kwOF",
  "kwTYPE",
  "kwLABEL",
  "kwOR",
  "kwREPEAT",
  "kwUNTIL",
  "kwDOWNTO",
  "kwMOD",
  "kwPACKED",
  "kwSET",
  "kwCASE",
  "kwGOTO",
  "kwNIL",
  "kwNOT",
  "kwTO",
  "kwWITH",
  "COMMA",
  "EQUAL",
  "LPAR",
  "RPAR",
  "COLON",
  "AMPERSAND",
  "DOLLAR_SIGN",
  "R_SQR_BRAK",
  "L_SQR_BRAK",
  "kwINTEGER",
  "kwREAL",
  "kwCHARACTER",
  "kwBOOLEAN",
  "kwENUMERATOR",
  "kwSUBRANGE",
  "kwARRAY",
  "kwPOINTER",
  "kwFORWARD",
  "NOT_EQUAl",
  "kwExit",
  "kwINFO",
  "kwDECLARE",
  "kwASSERT",
  "kwCHECK",
  "kwGET",
  "kwDISTINCT"
}; //symbol names in the same order as in LexSymbolType

const LexSymbolType dataTypes[7] =   { kwINTEGER, kwREAL, kwCHARACTER , kwBOOLEAN, kwENUMERATOR, kwSUBRANGE, kwPOINTER };

static int character;   // input symbol            
static InputCharType input; // input symbol type

void readInput(void) {
  character = getChar();
  if ((character>='A' && character<='Z') || (character>='a' && character<='z') || character == '_')
    input = LETTER;
  else if (character>='0' && character<='9')
    input = NUMBER;
  else if (character == EOF)
    input = END;
  else if (character <= ' ' || character == '|' || character == ';')
    input = WHITE_SPACE;
  else
    input = NO_TYPE;
}

const struct {const char* slovo; LexSymbolType symb;} keyWordTable[] = {
 {"if", kwIF},
  {"then", kwTHEN},
  {"else", kwELSE},
  {"for", kwFOR},
  {"do", kwDO},
  {"while", kwWHILE},
  {"var", kwVAR},
  {"program", kwPROGRAM},
  {"uses", kwUSES},
  {"const", kwCONST},
  {"function", kwFUNCTION},
  {"begin", kwBEGIN},
  {"end", kwEND},
  {"procedure", kwPROCEDURE},
  {"and", kwAND},
  {"div", kwDIV},
  {"file", kwFILE},
  {"forward", kwFORWARD},
  {"in", kwIN},
  {"exit", kwExit},
  {"of", kwOF},
  {"type", kwTYPE},
  {"label", kwLABEL},
  {"or", kwOR},
  {"repeat", kwREPEAT},
  {"until", kwUNTIL},
  {"downto", kwDOWNTO},
  {"mod", kwMOD},
  {"packed", kwPACKED},
  {"set", kwSET},
  {"declare", kwDECLARE},
  {"info", kwINFO},
  {"assert", kwASSERT},
  {"case", kwCASE},
  {"check", kwCHECK},
  {"get", kwGET},
  {"goto", kwGOTO},
  {"nil", kwNIL},
  {"not", kwNOT},
  {"to", kwTO},
  {"with", kwWITH},
  {"integer", kwINTEGER},
  {"real", kwREAL},
  {"character", kwCHARACTER},
  {"boolean", kwBOOLEAN},
  {"enumerator", kwENUMERATOR},
  {"array", kwARRAY},
  {"pointer", kwPOINTER},
  {"distinct", kwDISTINCT},
  {NULL, (LexSymbolType) 0} // Mark the end of the array with a NULL word and 0 symbol
};

LexSymbolType keyWord(char* id) {
  int i = 0;
  while (keyWordTable[i].slovo)
    if (strcmp(id, keyWordTable[i].slovo)==0)
      return keyWordTable[i].symb;
    else
      i++;
  return IDENT;
}

void error(const char* text) {
  std::cerr << '\n' << text << '\n';
  throw std::runtime_error(text);
}

LexicalSymbol readLexem(void) {
  LexicalSymbol data;
  int identLen;
  int stringLen;
  int base = 10;
  int divider = 10;
  int digit;
q0:
  switch (character) {
    case '{':
      readInput();
      goto q1;
    case '[':
      readInput();
      data.type = L_SQR_BRAK;
      return data;
    case ']':
      readInput();
      data.type = R_SQR_BRAK;
      return data;
    case '&':
      data.type = AMPERSAND;
      data.number = 0;
      base = 8;
      data.type = NUMB;
      readInput();
      goto q3dx;
    case '$':
      data.type = DOLLAR_SIGN;
      data.number = 0;
      base = 16;
      data.type = NUMB;
      readInput();
      goto q3dx;
    case '(':
      data.type = LPAR;
      readInput();
      return data;
    case ')':
      data.type = RPAR;
      readInput();
      return data;
    case '+':
      data.type = PLUS;
      readInput();
      return data;
    case '-':
      data.type = MINUS;
      readInput();
      return data;
    case '*':
      data.type = MULTIPLY;
      readInput();
      return data;
    case '/':
      data.type = DIVIDE;
      readInput();
      return data;
//    case ';':
//      data.type = SEMICOLON;
//      readInput();
//      return data;
    case ',':
      data.type = COMMA;
      readInput();
      return data;
    case '=':
      data.type = EQUAL;
      readInput();
      return data;
    case '<':
      readInput();
      goto q4;
    case '>':
      readInput();
      goto q6;
    case ':':
      readInput();
      goto q5;
    case '.':
      data.numberr = 0;
      data.type = NUMBR;
      readInput();
      goto q3rr;
    case '\'':
      data.type = STRING;
      stringLen = 0;
      readInput();
      goto q7;
    case '\"':
      data.type = STRING;
      stringLen = 0;
      readInput();
      goto q8;
    default:;
  }
  switch (input) {
    case WHITE_SPACE:
      readInput();
      goto q0;
    case END:
      data.type = EOI;
      return data;
    case LETTER:
      identLen = 1;
      data.ident[0] = character;
      readInput();
      goto q2;
    case NUMBER:
      data.number = character - '0';
      base = 10;
      data.type = NUMB;
      readInput();
      goto q3dx;
    default:
      data.type = ERR;
      error("Invalid symbol.");
      return data;
  }

q3dx:
  goto q3;

q1:
  switch(character) {
    case '}':
      readInput();
      goto q0;
    case '\\':
      readInput();
      goto q11;
    default:;
  }
  switch(input) {
    case END:
      data.type = ERR;
      error("Uneexpected end of file in a comment.");
      return data;
    default:
      readInput();
      goto q1;
  }

q11:
  switch(character) {
    case '}':
      readInput();
      goto q1;
    case '\\':
      readInput();
      goto q1;
    default:;
      error("Unexpected escape symbol \\.");
  }

q2:
  switch(input) {
    case LETTER:
    case NUMBER:
      data.ident[identLen] = character;
      identLen++;
      readInput();
      goto q2;
    default:
      data.ident[identLen] = 0;
      data.type = keyWord(data.ident);
      return data;
  }

q3:
  switch(character) {
    case '.':
      if (base != 10) {
        error("Decimal numbers only supported in base 10!");
      }
      data.numberr = (float)data.number;
      data.type = NUMBR;
      readInput();
      goto q3r;
  }
  switch(input) {
    case NUMBER:
    case LETTER:
      if (character >= 'a') {
        digit = (character - 'a') + 10;
      } else if (character >= 'A') {
        digit = (character - 'A') + 10;
      } else {
        digit = (character - '0');
      }
      if (digit >= base) {
        error("Digit not allowed in this base!");
      }
      data.number = base * data.number + digit;
      readInput();
      goto q3;
    default:
      return data;
  }

q3rr:   // DOT , same as q3r2
  switch(input) {
    case NUMBER:
      goto q3r;
  }
  data.type = DOT;
  return data;

q3r:
  switch(input) {
    case NUMBER:
      digit = (character - '0');
      data.numberr += ((float)digit)/divider;
      divider *= 10;
      readInput();
      goto q3r;
    default:
      return data;
  }

q4:
  switch(character) {
    case '=':
      data.type = LESS_OR_EQ;
      readInput();
      return data;
    case '>':
      data.type = NOT_EQUAl;
      readInput();
      return data;
    default:;
  }
  
  switch(input) {
    default:
      data.type = LESS;
      return data;
  }

q5:
  switch(character) {
    case '=':
      readInput();
      data.type = ASSIGN;
      return data;
    default:
      data.type = COLON;
      return data;
  }
  // switch(input) {
  //   default:
  //     data.type = ERR;
  //     error("Expected \'=\'.");
  //     return data;
  // }

q6:
  switch(character) {
    case '=':
      data.type = GREATER_OR_EQ;
      readInput();
      return data;
    default:;
  }
  switch(input) {
    default:
      data.type = GREATER;
      return data;
  }

  // STINGS
q7:
  switch (character){
    case '\\':
      readInput();
      goto q7q;
    case '\'':
      data.string[stringLen] = 0;
      readInput();
      return data;
  }

q8:
  switch (character){
    case '\\':
      readInput();
      goto q7q;
    case '\"':
      data.string[stringLen] = 0;
      readInput();
      return data;
  }
  switch (input){
    case END:
      error("Unterminated string");
  }
  data.string[stringLen] = character;
  stringLen++;
  readInput();
  goto q7;


q7q: // quoting in strings
  switch (input){
    case END:
      error("Unterminated string");
  }
  switch (character){
    case '\\':
      data.string[stringLen] = character;
      stringLen++;
      readInput();
      goto q7;
    case '"':
      data.string[stringLen] = character;
      stringLen++;
      readInput();
      goto q7;
    case 'n':
      data.string[stringLen] = '\n';  //new line
      stringLen++;
      readInput();
      goto q7;
    case 'r':
      data.string[stringLen] = '\r';   // carage return
      stringLen++;
      readInput();
      goto q7;
    case 't':
      data.string[stringLen] = '\t';   // tabulator
      stringLen++;
      readInput();
      goto q7;
    case 'b':
      data.string[stringLen] = '\b';   // back
      stringLen++;
      readInput();
      goto q7;
    default:
      data.string[stringLen] = '\\';
      stringLen++;
      data.string[stringLen] = character;
      stringLen++;
      readInput();
      goto q7;

  }

} 

int initLexan(char *fileName) {
  if(!initInput(fileName)) return 0;
  readInput();
  return 1;
}
