#include <iostream>
#include <string>
using namespace std;
/*
;; exp ::= int | (read) | (- exp) | (+ exp exp)
;; R0 ::= (program exp)
*/


class Var{
  public:
  void counterplusplus() { counter++;}
  string label;
  static int counter;
  static void reset() {counter = 0;}
  Var (string label) {this->label = label + "_" + to_string(counter++); }
  Var (Var *base) {this->label = base->label + "_" + to_string(counter++); }
  string toString() {return label;}
};
int Var::counter = 0;

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

class RRead : public RExpr {
  public:
  RRead() { }
  string toString() {return "(read)";}

};

class RNeg : public RExpr{
  public:
  RExpr *arg;
  RNeg (RExpr *arg) {this->arg = arg;}
  string toString() { return "(- " + arg->toString() + ")";}
};

class RAdd : public RExpr{
  public:
  RExpr *lhs;
  RExpr *rhs;
  RAdd(RExpr *lhs, RExpr *rhs) {this->lhs = lhs; this->rhs = rhs;}
  string toString() { return "(+ " + lhs->toString() + " " + rhs->toString() + ")";}

};


class RRef : public RExpr {
  public:
  Var *x;
  RRef( Var *x) {this->x = x;}
  string toString() { return x->toString();}

};

class RLet : public RExpr{
  public:
  Var *x;
  RExpr *xe;
  RExpr *be;

  RLet(Var *x, RExpr *xe, RExpr *be){
    this->x = x; this->xe = xe; this->be = be;
  }
  string toString() { return "(let " + x->toString() + " " + xe->toString() + " " + be->toString() + ")";}
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

//returns new RAdd(n, n) where n is how many times it returns
static RExpr *pow2(int n){
  if (n == 0) { return new RNum(1);}
  else {
    RExpr *subexpr = pow2(n - 1);
    return new RAdd(subexpr, subexpr);
  }
}

int main(void){

  RExpr* exp1 = new RNum(5);
  cout << exp1->toString();

  RExpr *exp2 = new RRead();
  cout << exp2->toString();
  
  RExpr *exp3 = new RNeg(new RNum(5));
  cout << exp3->toString() << endl;

  RExpr *exp4 = (new RAdd(new RNum(4), new RAdd(new RNum(5), new RNum(6))));
  cout << exp4->toString() << endl;

  RExpr *exp5 = new RNeg(new RAdd(new RNum(4), new RAdd(new RNum(5), new RNum(6))));
  cout << exp5->toString() << endl;

  Var *x = new Var("x");

  RExpr *ex1 =
          new RLet(x , new RNum(10),
                  new RAdd( new RNeg( new RRef(x)), new RRead()));
  cout << ex1->toString()<< endl;

  RExpr *timmy = 
           new RLet(x, new RNum(10), 
                  new RAdd(new RNum(5), new RRef(x)));
  cout << "timmy = " << timmy->toString() << endl;

  RExpr *test = new RNeg(
                  new RNeg( 
                    new RAdd( new RNum(18), new RNeg( 
                      new RAdd(new RNum(5),new RNum(5))))));
  cout << "test = " << test->toString() << endl;

  
  cout << pow2(2)->toString() << endl;
  
  return 0;
}
