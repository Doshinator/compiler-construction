//c prog

//c expr
class CExpr{
    public:
        virtual string toString() = 0;
};

class CEArg : public CExpr{
    public:
        CEArg *arg;
        CEArg( CEArg *arg ) { this.arg = arg; }
        string toString() { return arg->toString(); } 
};

class CERead : public CExpr{
    public:
        string toString() { return "(read)";}

};

class CENeg : public CExpr {
    public:
        CEArg *arg;
        CENeg( CEArg *arg ) { this.arg = arg; }
        string toString() { return "(- " + arg->toString() + ")"; }

};

class CEAdd : public CExpr{
    public:
    CEArg *lhs;
    CEArg *rhs;
    CEArg(CEArg *lhs, CEArg *rhs){ this->lhs = lhs; this->rhs = rhs;}
    string toString() { return "(+ " + lhs->toString() + " " + rhs->toString() + ")";}

};

//c arg

class CArg{
    virtual string toString() = 0;
};

class CAInt : public CArg{
    public:
        int n;
        CAInt(int n) { this->n = n;}
        string toString() {return to_string(n);}
};

class CARef : public CArg{
    public:
        Var *x;
        CARef(Var *x) {this->x = x;}
        string toString() {return x->toString();}
};

// c stmt
class CStmt {
    virtual string toString() = 0;
};


class CSSet{
     public:
        Var *var;
        CExpr *expr;
        CSSet(Var *var, CExpr *expr){ this->var = var; this->exp = expr;}
        string toString() = {return "(set! " + var->toString() + " " + expr->toString() + ")"; }
};


