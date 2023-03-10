#include "tree.h"
#include<iostream>


int LogErrorV(const char* Str) {
  std::cerr << "Error: " << Str << std::endl;
  std::exit(1);
}

Constraint &Constraint::intersect(Constraint a) {
  _segments._left = std::max(_segments._left, a._segments._left);
  _segments._right = std::min(_segments._right, a._segments._right);
  return *this;
}

Constraint &Constraint::uni(Constraint a) {
  _segments._left = std::min(_segments._left, a._segments._left);
  _segments._right = std::max(_segments._right, a._segments._right);

  return *this;
}


IntConst::IntConst(int c){
    val = c;
}

BinOp::BinOp(LexSymbolType o, Node *l, Node *r){
    op = o; left = l; right = r;
}

int BinOp::codegen(const std::map<std::string, int> &vars) {
    int L = left->codegen(vars);
    int R = right->codegen(vars);


    switch (op) {
        case PLUS:
            return L + R;
        case MINUS:
          return L - R;
        case MULTIPLY:
          return L * R;;
        case DIVIDE:
          return L / R;
        case kwMOD:
            return L % R;
        case kwDIV:
            return L / R;
        case LESS:
            return L < R;
        case LESS_OR_EQ:
            return L <= R;
        case GREATER:
            return L > R;
        case GREATER_OR_EQ:
            return L >= R;
        case NOT_EQUAl:
            return L != R;
        case EQUAL:
            return L == R;
        case kwAND:
            return L && R;
        case kwOR:
            return L || R;

        default:
            return LogErrorV("invalid binary operator");
    }
}

std::map<std::string, Constraint> BinOp::getConstraints(const std::vector<Node *> &vars) {
  auto L = left->getConstraints(vars);
  auto R = right->getConstraints(vars);

  std::map<std::string, Constraint> res;
  switch (op) {
    case PLUS:{
      auto &lc = L[NODE_CONSTR_NAME];
      auto &rc = R[NODE_CONSTR_NAME];

      res[NODE_CONSTR_NAME] = Constraint(lc.getMin() + rc.getMin(), lc.getMax() + rc.getMax());
      return res;
    }
    case MINUS:{
      auto &lc = L[NODE_CONSTR_NAME];
      auto &rc = L[NODE_CONSTR_NAME];

      res[NODE_CONSTR_NAME] = Constraint(lc.getMin() - rc.getMax(), lc.getMax() - rc.getMin());
      return res;
    }

// TODO finish operation

//    case MULTIPLY:
//      return L * R;
//    case DIVIDE:
//      return L / R;
//    case kwMOD:
//      return L % R;
//    case kwDIV:
//      return L / R;
    case LESS:{
      if (left->getType() == VarType) {
        auto var = (VarNode *) left;
        res[var->getName()] = Constraint(MINUS_INF, R[NODE_CONSTR_NAME].getMax() - 1);
      }

      if (right->getType() == VarType) {
        auto var = (VarNode *) right;
        res[var->getName()] = Constraint(L[NODE_CONSTR_NAME].getMin() + 1, PLUS_INF);
      }
      res[NODE_CONSTR_NAME] = Constraint(0, 1);
      return res;
    }

    case LESS_OR_EQ:{
      if (left->getType() == VarType) {
        auto var = (VarNode *) left;
        res[var->getName()] = Constraint(MINUS_INF, R[NODE_CONSTR_NAME].getMax());
      }

      if (right->getType() == VarType) {
        auto var = (VarNode *) right;
        res[var->getName()] = Constraint(L[NODE_CONSTR_NAME].getMin(), PLUS_INF);
      }
      res[NODE_CONSTR_NAME] = Constraint(0, 1);
      return res;
    }
    case GREATER:{
      if (right->getType() == VarType) {
        auto var = (VarNode *) right;
        res[var->getName()] = Constraint(MINUS_INF, L[NODE_CONSTR_NAME].getMax() - 1);
      }

      if (left->getType() == VarType) {
        auto var = (VarNode *) left;
        res[var->getName()] = Constraint(R[NODE_CONSTR_NAME].getMin() + 1, PLUS_INF);
      }
      res[NODE_CONSTR_NAME] = Constraint(0, 1);
      return res;
    }
    case GREATER_OR_EQ:{
      if (right->getType() == VarType) {
        auto var = (VarNode *) right;
        res[var->getName()] = Constraint(MINUS_INF, L[NODE_CONSTR_NAME].getMax());
      }

      if (left->getType() == VarType) {
        auto var = (VarNode *) left;
        res[var->getName()] = Constraint(R[NODE_CONSTR_NAME].getMin(), PLUS_INF);
      }
      res[NODE_CONSTR_NAME] = Constraint(0, 1);
      return res;
    }
// TODO finish operation

//    case NOT_EQUAl:
//      return L != R;
//    case EQUAL:
//      return L==R;
    case kwAND: {
      res = L;
      for (auto &p: R) {
        if (res.find(p.first) == res.end()) {
          res[p.first] = p.second;
        } else {
          res[p.first].intersect(p.second);
        }
      }
      res[NODE_CONSTR_NAME] = Constraint(0, 1);
      return res;
    }
    case kwOR: {
        res = L;
        for (auto &p: R) {
          if (res.find(p.first) == res.end()) {
            res[p.first] = p.second;
          } else {
            res[p.first].uni(p.second);
          }
        }
        res[NODE_CONSTR_NAME] = Constraint(0, 1);
        return res;
      return res;
    }

    default:
      res[NODE_CONSTR_NAME] = Constraint();
      return res;
  }
}

UnOp::UnOp(LexSymbolType o, Node*oper) {
    op = o;
    operand = oper;
}
int UnOp::codegen(const std::map<std::string, int> &vars) {
  int L = operand->codegen(vars);
  
  switch (op) {
      case kwNOT:
        return (L == 0 ? 1 : 0);
      case PLUS:
          return L;
      case MINUS:
        return -L;
    default:
        return LogErrorV("invalid unary operator");
  }
}

std::map<std::string, Constraint>  UnOp::getConstraints(const std::vector<Node *> &vars) {
  auto L = operand->getConstraints(vars);

  std::map<std::string, Constraint> res;

  switch (op) {
      //    case kwNOT:
      //      return (L == 0 ? 1 : 0);
    case PLUS:
      return L;
    case MINUS: {
      L[NODE_CONSTR_NAME]._segments._left *= -1;
      L[NODE_CONSTR_NAME]._segments._right *= -1;

      return L;
    }
    default:
      res[NODE_CONSTR_NAME] = Constraint();
      return res;
  }
}

VarNode::VarNode(const std::string &N){
    name = N;
}

std::string& VarNode::getName() {
    return name;
}

Parantesis::Parantesis(Node * e){
    expr = e;
}

int Parantesis::codegen(const std::map<std::string, int> &vars) {
    return expr->codegen(vars);
}
