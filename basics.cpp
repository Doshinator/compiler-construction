#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <functional>
#include <exception>      // std::exception
#include <stdlib.h>


using namespace std;
/*
;; exp ::= int | (read) | (- exp) | (+ exp exp)
;; R0 ::= (program exp)
*/




//uniquify ( map<var->var> , e)

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
  //virtual int eval(string::iterator in, map<Var,int> env) = 0 ;
};

class RNum : public RExpr{
  public:
  int num;
  RNum(int num) {this->num = num;}
  string toString() { return to_string(num);}
  //int eval(string::iterator in, map<Var,int> env){return num;}
};

class RRead : public RExpr {
  public:
  RRead() { }
  string toString() {return "(read)";}
  //int eval(string::iterator in, map<Var,int> env){return atoi(in.next());}

};

class RNeg : public RExpr{
  public:
  RExpr *arg;
  RNeg (RExpr *arg) {this->arg = arg;}
  string toString() { return "(- " + arg->toString() + ")";}
  //int eval(string::iterator in, map<Var,int> env){return -1 * arg->eval(in, env);}
};

class RAdd : public RExpr{
  public:
  RExpr *lhs;
  RExpr *rhs;
  RAdd(RExpr *lhs, RExpr *rhs) {this->lhs = lhs; this->rhs = rhs;}
  string toString() { return "(+ " + lhs->toString() + " " + rhs->toString() + ")";}
  //int eval(string::iterator in, map<Var,int> env){return lhs->eval(in, env) + rhs->eval(in, env);}
};


class RRef : public RExpr {
  public:
  Var *x;
  RRef( Var *x) {this->x = x;}
  string toString() { return x->toString();}
  //int eval(string::iterator in, map<Var,int> env){return env->ref(x);}

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
 /* int eval(string::iterator in, map<Var,int> env){ 
    int what_is_x = xe->eval(in, env);
    auto env_with_x = xe->set(x, what_is_x);
    return be->eval(in, env_with_x);}
  */
};




/*
class RBinop : public RExpr{
  RExpr left;
  RExpr right;
  R_binop op;
  RBinop(R_binop op, RExpr left,RExpr right) {this->op = op; this->left = left; this->right = right;}

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

/*
static int test_passed = 0;

static void summary(){
    cout << test_passed << " test(s) passed!" << endl;
}

static void check(string which, std::function<void(int)> te, int expected){
    try{
        int actual = te.get(); // <-- te.get?? 
        if(actual != expected){
            cout << which << ": got " << actual << ", expected " << expected << endl;
            exit(1);
        } else {
            test_passed++;
            }
    }
    catch (RuntimeException x){
        cout << which << ": threw exception [" << x << "], expected " << expected << endl;
        exit(1);
    }

}

static void t(int ans, RExpr *e){
    Var::reset();
    cout << e->toString() << " =>";
    check("eval", [] -> eval(e), ans); //lambda??
}
*/


/*
template <typename K, typename V>
class IMap{
    public:
    map<K, V> hm;
    IMap() { (new map<K, V>());}
    
      V ref(K x){
        V r = hm.get(x);
        if( r == NULL){
            throw new runtime_error(x + " not found in hash map");
        }
        return r;
    }

    IMap<K, V> set(K x, V v){
        map<K, V> hmp = new map<K, V>(hm);
        hmp.put(x, v);
        return new IMap<K, V>(hmp);
    }

    IMap<K, V> merge(IMap<K,V> o){
        map<K, V> hmp = new map<K, V>(hm);
        hmp.putAll(o.hm);
        return new IMap<K, V>(hmp);
    }

    private:
    IMap(map<K,V> hm){ this->hm = hm;}
};

*/



static void t(int ans, RExpr *e){
    Var::reset();
    cout << e->toString() << " =>" << endl;
    
}





int main(void){
  
  Var *x = new Var("x");
  RExpr *ex1 = new RLet(x, new RNum(8),
                  new RAdd(new RLet(x, new RNum(10), new RRef(x)),new RRef(x)));
  cout << ex1->toString() << endl;

    t(5, new RNum(5));




  return 0;
}
