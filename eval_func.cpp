static int eval(RExpr *e){
    IMap<Var, int> env = new Imap<Var,int>();
    return e->eval(stdin(), env);
}

static iterator<string> stdin(){
    if (true){
        string inv[] = {"42"};
        return inv[0];
    } 
}