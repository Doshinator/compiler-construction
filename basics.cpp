#include <iostream>
#include <string>
using namespace std;
/*
;; exp ::= int | (read) | (- exp) | (+ exp exp)
;; R0 ::= (program exp)
*/

typedef enum {A_plus, A_minus, A_times, A_divide} R_binop;
class RExpr {
  public:
  virtual string toString() = 0;
};

class RNum : public RExpr{
  public:
  int num;
  RNum(int num) {this->num = num;}
  string toString() { return to_string(num);}
};

class RAdd : public RExpr{
  public:
  RExpr *lhs;
  RExpr *rhs;
  RAdd(RExpr *lhs, RExpr *rhs){ this->lhs = lhs; this->rhs = rhs;}
  string toString() { return " + ";}

};
/*
class RBinop : public RExpr{
  RExpr left;
  RExpr right;
  R_binop op;
  RBinop(R_binop op, RExpr left,RExpr right) {this->op = op; this->left = left; this->right = right;}

};
*/


/*
class Var {
  public:
  Var(string label) { this->label = label + "_" + counter++;}
  Var(Var base) { this->label = base.label + "_" + counter++;}
  string label;
  static int counter = 0;
  static void reset ( ) { count = 0; }
};
*/ 



int main(void){

  RExpr* exp1 = new RNum(5);
  cout << exp1->toString();

  RExpr *exp3 = new RAdd(RNum(5),exp1);
  cout << exp3->toString();
  


    return 0;
}
