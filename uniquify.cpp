static RExpr *uniquify(RExpr *e){
    map<Var, Var> r = new map<Var,Var> ();
    return e.uniquify(r);
}

RExpr uniquify(map<Var, Var> r) = 0;

