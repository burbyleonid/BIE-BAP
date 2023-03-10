/* parser.c */

#include "parser.h"
#include "lexan.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


Node *Expression(void);
Node *ExpressionPrime(Node *);
Node *Term(void);
Node *TermPrime(Node *);
Node *Factor(void);

LexicalSymbol Symb;

void CompareError(LexSymbolType s)
{
  printf("Error while comparing, expected %s.\n", symbTable[s]);
  return;
}

void ExpansionError(char *nonterminal, LexSymbolType s)
{
  printf("Error while expanding nonterminal %s, unexpected token %s.\n", nonterminal, symbTable[s]);
  return;
}

void SyntaxError(LexSymbolType ex, LexSymbolType cur)
{
  printf("Error expected token %s, current token is %s.\n", symbTable[ex], symbTable[cur]);
  return;
}

void Compare(LexSymbolType s)
{
  if (Symb.type == s)
    Symb = readLexem();
  else
    CompareError(s);
}

int Srovnani_NUMB()
{
  if (Symb.type == NUMB)
  {
    int shod = Symb.number;
    Symb = readLexem();
    return shod;
  }
  else
    CompareError(NUMB);
}

int initParser(char *fileName)
{
  if (!initLexan(fileName))
    return 0;
  Symb = readLexem();
  return 1;
}

Node *ExpressionTMP(int priority, bool flag = false, bool constFlag = false);
Node *AssertDeclaration();
Node *DeclareDeclaration();
Node *SetDeclaration();
Node *DefaultDeclaration();


Node *ExpressionTMP(int priority, bool unaryFlag, bool constFlag)
{
  Node *tmp;
  switch (Symb.type)
  {
    case kwAND:
    case kwOR:
    {
      LexSymbolType op = Symb.type;
      Symb = readLexem();
      auto lhs = ExpressionTMP(0);

      if (lhs == NULL) {
        return NULL;
      }

      auto rhs = ExpressionTMP(0);

      if (rhs == NULL) {
        return NULL;
      }
      tmp = new BinOp(op, lhs, rhs);
      while (Symb.type != RPAR) {
        rhs = ExpressionTMP(0);
        if (rhs == NULL) {
          return NULL;
        }
        tmp = new BinOp(op, tmp, rhs);
      }

      return tmp;

      break;
      break;
    }
    case kwNOT:
    {
      LexSymbolType op = Symb.type;
      Symb = readLexem();
      auto lhs = ExpressionTMP(0);

      if (lhs == NULL) {
        return NULL;
      }

      return new UnOp(op, lhs);

      break;
    }
    case PLUS:
    case MINUS:
    {
      LexSymbolType op = Symb.type;
      Symb = readLexem();
      auto lhs = ExpressionTMP(0);

      if (lhs == NULL) {
        return NULL;
      }

      if (Symb.type == RPAR) {
        return new UnOp(op, lhs);
      }

      while (Symb.type != RPAR) {
        auto rhs = ExpressionTMP(0);
        if (rhs == NULL) {
          return NULL;
        }
        lhs = new BinOp(op, lhs, rhs);
      }

      return lhs;

      break;
    }
    case MULTIPLY:
    case DIVIDE:
    case kwMOD:
    case kwDIV:
    case LESS:
    case LESS_OR_EQ:
    case GREATER:
    case GREATER_OR_EQ:
    case NOT_EQUAl:
    case EQUAL:
    {
      LexSymbolType op = Symb.type;
      Symb = readLexem();
      auto lhs = ExpressionTMP(0);

      if (lhs == NULL) {
        return NULL;
      }

      auto rhs = ExpressionTMP(0);

      if (rhs == NULL) {
        return NULL;
      }

      return new BinOp(op, lhs, rhs);

      break;
    }
    case LPAR:
    {
      Node *expr;
      Symb = readLexem();
      if (!(expr = ExpressionTMP(0, false, constFlag)))
      {
        return NULL;
        break;
      }
      if (Symb.type != RPAR)
      {
        SyntaxError(RPAR, Symb.type);
        return NULL;
        break;
      }
      Symb = readLexem();
      return new Parantesis(expr);

      break;
    }
    case IDENT:
    {
      VarNode *var = new VarNode(Symb.ident);
      Symb = readLexem();
      return var;
      break;
    }
    case NUMB:
    {
      IntConst *integer = new IntConst(Symb.number);
      Symb = readLexem();
      return integer;
      break;
    }
    default:
      std::cout << "Error in Expression. Expected symbol : " << symbTable[Symb.type] << std::endl;
      tmp = NULL;
      break;
  }

  return tmp;
};


Node *AssertDeclaration() {
  if (Symb.type != kwASSERT) {
    SyntaxError(kwASSERT, Symb.type);
    return nullptr;
  }
  Symb = readLexem();

  return ExpressionTMP(0);
}

Node *DeclareDeclaration() {
  std::cout << "DeclareDeclaration start" << std::endl;
  if (Symb.type != kwDECLARE) {
    SyntaxError(kwDECLARE, Symb.type);
    return nullptr;
  }
  Symb = readLexem();
  if (Symb.type != MINUS) {
    SyntaxError(kwDECLARE, Symb.type);
    return nullptr;
  }
  Symb = readLexem();
  if (Symb.type != IDENT || strcmp(Symb.ident, "fun") != 0) {
    SyntaxError(IDENT, Symb.type);
    std::cout << Symb.ident << " != fun" << std::endl;
    return nullptr;
  }

  Symb = readLexem();
  if (Symb.type != IDENT) {
    SyntaxError(IDENT, Symb.type);
    return nullptr;
  }
  std::string ident(Symb.ident);
  VarNode *var = new VarNode(ident);

  std::cout << Symb.ident << std::endl;


  Symb = readLexem();
  if (Symb.type != LPAR) {
    SyntaxError(LPAR, Symb.type);
    return nullptr;
  }

  Symb = readLexem();
  if (Symb.type != RPAR) {
    SyntaxError(RPAR, Symb.type);
    return nullptr;
  }
  Symb = readLexem();
  if (Symb.type != IDENT || strcmp(Symb.ident, "Int") != 0) {
    SyntaxError(IDENT, Symb.type);
    std::cout << Symb.ident << " != Int" << std::endl;
    return nullptr;
  }

  Symb = readLexem();
  std::cout << "DeclareDeclaration end" << std::endl;

  return var;
}

Node *SetDeclaration() {
  std::cout << "SetDeclaration start" << std::endl;
  while (Symb.type != RPAR){
    std::cout << symbTable[Symb.type] << std::endl;
    Symb = readLexem();
  }
  std::cout << "SetDeclaration end" << std::endl;
  return NULL;
}

Node *DefaultDeclaration() {
  Node *tmp;
  if (Symb.type == LPAR) {
    Symb = readLexem();
    switch (Symb.type) {
      case kwExit:
        tmp = NULL;
        Symb = readLexem();
        break;
      case kwGET:
      case kwCHECK:
      case kwSET:
        SetDeclaration();
        tmp = new IntConst(5);
        break;
      case kwDECLARE:
        tmp = DeclareDeclaration();
        break;
      case kwASSERT:
        tmp = AssertDeclaration();
        break;

      default:
        auto asd = 5;
        break;
    }
  }

  if (Symb.type != RPAR) {
    SyntaxError(RPAR, Symb.type);
    exit(-1);
    return NULL;
  }
  if (tmp == NULL) {
    return NULL;
  }
  Symb = readLexem();
  return tmp;
}

std::map<std::string, int> test(int idx, std::vector<VarNode *> &vars,
                                std::map<std::string, int> &curr,
                                std::vector<Node*> &constraints)
{
  if (idx == vars.size()) {
    bool flag = true;
    for (int i = 0; i < constraints.size(); ++i) {
      if (constraints[i]->codegen(curr) == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return curr;
    }
    return std::map<std::string, int>();
  }

  for (int i = vars[idx]->cons._segments._left; i <= vars[idx]->cons._segments._right; ++i) {
    curr[vars[idx]->getName()] = i;
    auto res = test(idx + 1, vars, curr, constraints);
    if (res.size() != 0) {
      return res;
    }
  }

  return std::map<std::string, int>();
}

Node *Program()
{
  Node *tmp;
  std::vector<Node *> v;
  while ((tmp = DefaultDeclaration())) {
    v.push_back(tmp);

    if (Symb.type == EOI) {
      break;
    }
  }

  std::vector<VarNode *> vars;
  std::map<std::string, VarNode *> mVars;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i]->getType() == VarType) {
      vars.push_back((VarNode *)v[i]);
      mVars[((VarNode *)v[i])->getName()] = (VarNode *)v[i];
    }
  }

  std::vector<Node*> constraints;

  for (int i = 0; i < v.size(); ++i) {
    if (v[i]->getType() == ParType) {
      constraints.push_back(v[i]);
    }
  }

  while (true) {
    bool flag = false;
    for (int i = 0; i < constraints.size(); ++i) {
      auto res = constraints[i]->getConstraints(std::vector<Node*>());
      for (auto &p : res) {
        if (p.first != NODE_CONSTR_NAME) {
          auto tmp = mVars[p.first]->cons._segments;
          mVars[p.first]->cons.intersect(p.second);
          if (tmp._left != mVars[p.first]->cons._segments._left || tmp._right != mVars[p.first]->cons._segments._right) {
            flag = true;
          }
        }
      }
    }
    if (!flag) {
      break;
    }
  }

  std::map<std::string, int> cur;
  auto res = test(0, vars, cur, constraints);

  if (res.size()) {
    std::cout << "SAT:" << std::endl;
    for (const auto &v : res) {
      std::cout << v.first << " = " << v.second << std::endl;
    }
  } else {
    std::cout << "Not SAT" << std::endl;
  }


  // auto debug = 5;

  return nullptr;
}
