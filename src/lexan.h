#ifndef _Lexan_
#define _Lexan_

typedef enum {
  IDENT, 
  NUMB, NUMBR, STRING, ARRAY,
  PLUS, MINUS, MULTIPLY, DIVIDE, 
  LESS, LESS_OR_EQ, GREATER, GREATER_OR_EQ, 
  ASSIGN, DOT, SEMICOLON,
  kwIF, kwTHEN, kwELSE, kwFOR, kwDO, kwWHILE, 
  kwPROGRAM, kwUSES, kwCONST, kwFUNCTION, kwBEGIN,
  kwEND, kwPROCEDURE,
  EOI, ERR, kwVAR, kwAND, kwDIV, kwFILE,
  kwIN, kwOF, kwTYPE, kwLABEL, kwOR,
  kwREPEAT, kwUNTIL, kwDOWNTO, kwMOD, kwPACKED, 
  kwSET, kwCASE, kwGOTO, kwNIL, kwNOT, kwTO, kwWITH, 
  COMMA, EQUAL, LPAR, RPAR, COLON , AMPERSAND, DOLLAR_SIGN, R_SQR_BRAK, L_SQR_BRAK, 
  kwINTEGER, kwREAL, kwCHARACTER , kwBOOLEAN, kwENUMERATOR, kwSUBRANGE, kwARRAY, kwPOINTER,
  kwFORWARD, NOT_EQUAl, kwExit,
  kwINFO, kwDECLARE, kwASSERT, kwCHECK, kwGET, kwDISTINCT
} LexSymbolType;

extern const char *symbTable[79];

extern const LexSymbolType dataTypes[7];

#define MAX_IDENT_LEN 32
#define MAX_STRING_LEN 128

typedef struct LexicalSymbol {
  LexSymbolType type;
  char      ident[MAX_IDENT_LEN];  /* atribute of IDENT token */
  char      string[MAX_STRING_LEN];/* atribute of STRING token */
  int       number;                /* atribute of NUMB token */
  float     numberr;               /* atribute of NUMBR token */
} LexicalSymbol;

LexicalSymbol readLexem(void);
int initLexan(char*);

#endif
