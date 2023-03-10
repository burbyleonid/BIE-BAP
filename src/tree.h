#ifndef _NODE_
#define _NODE_
#include <vector>
#include <map>
#include <string>
#include "lexan.h"


#define PLUS_INF (250)
#define MINUS_INF (-PLUS_INF)
#define NODE_CONSTR_NAME ("___nodeConstr")


typedef enum {
  NoType = -1,
  VarType,
  IntType,
  BinOpType,
  UnOpType,
  ParType,
} NodeType;

struct Segment {
  int _left;
  int _right;
  Segment() {
    _left = MINUS_INF;
    _right = PLUS_INF;
  }

  Segment(int left, int right) {
    _left = std::max(left, MINUS_INF);
    _right = std::min(right, PLUS_INF);
  }
};

struct Constraint {

  Segment _segments;

  Constraint() {
  }

  Constraint(int left, int right) {
    _segments = Segment(left, right);

  }

  int getMin() const { return _segments._left; }
  int getMax() const { return _segments._right;}

  Constraint &intersect(Constraint a);
  Constraint &uni(Constraint a);
};


void InitializeModule();

void RunCodeGen();


class Node {
public:
  virtual int getType() { return NoType; }

  virtual int codegen(const std::map<std::string, int> &vars) {return 0;};
  // Gives constraints on variables in an expression + constraints on the value of the expression itself in map[NODE_CONSTR_NAME]
  virtual std::map<std::string, Constraint> getConstraints(const std::vector<Node *> &vars) { return std::map<std::string, Constraint>();};
};

class IntConst : public Node {
  int val;
public:
  IntConst(int c);
  int codegen(const std::map<std::string, int> &vars) override { return val; }
  virtual int getType() override { return IntType; }
  std::map<std::string, Constraint> getConstraints(const std::vector<Node *> &vars) override { std::map<std::string, Constraint> m; m[NODE_CONSTR_NAME] = Constraint(val, val); return m;};
};

class BinOp : public Node {
  LexSymbolType  op;
  Node  *left, *right;
public:
  BinOp(LexSymbolType, Node*, Node*);
  virtual int getType() override { return BinOpType; }
  int codegen(const std::map<std::string, int> &vars) override;
  std::map<std::string, Constraint> getConstraints(const std::vector<Node *> &vars) override;
};

class UnOp : public Node {
  LexSymbolType  op;
  Node  *operand;
public:
  UnOp(LexSymbolType, Node*);
  virtual int getType() override { return UnOpType; }
  int codegen(const std::map<std::string, int> &vars) override;
  std::map<std::string, Constraint> getConstraints(const std::vector<Node *> &vars) override;
};

class VarNode : public Node{
public:
  std::string name;
  Constraint cons;
public:
  VarNode(const std::string &N);
  int codegen(const std::map<std::string, int> &vars) override { return vars.find(name)->second; }
  std::string &getName();
  virtual int getType() override { return VarType; }
  std::map<std::string, Constraint> getConstraints(const std::vector<Node *> &vars) override { std::map<std::string, Constraint> c; c[name] = cons;c[NODE_CONSTR_NAME] = cons; return c;}
};

class Parantesis : public Node{
  Node * expr;
public:
  Parantesis(Node * e);
  int codegen(const std::map<std::string, int> &vars) override;
  virtual int getType() override { return ParType; }
  std::map<std::string, Constraint> getConstraints(const std::vector<Node *> &vars) override { return expr->getConstraints(vars);}
};

#endif

