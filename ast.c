/* Doshinator Feb-14-2018 */
#include <stio.h>
#include <stdlib.h>

void *checked_malloc(int len) {
    void *p = malloc(len); 
    assert(p);
    return p;
}
//STMT
struct A_stm_{
    enum {A_compoundStm, A_assignStm, A_printStm} kind;
    //one constructor that belongs in the union for lhs symbole for grammar 1.3
    //compoundstm, assignstm, printstm
    union { struct {A_stm stm1, stm2} compound;    //stm -> stm; stm;           |s1;s2 executes statement s1, then statement s2
            struct {string id; A_exp exp;} assign; //stm -> id := Exp           |i :=e evaluates the expression e, then stores result in variable i
            struct {A_expList exps;} print;        //stm -> print (ExpList)     |print(e1 ... en) prints value of all expressions from left to right
    }u;
    
};

/*
    Exp -> id               (IdExp)     |Identifier expression, like i, yields current content of variable i
    Exp -> num              (NumExp)    |num evaluates to named integer
    Exp -> Exp Binop Exp    (OpExp)     |operator expression e1 op e2 evaluates e1, then e2, then applies binop
    Exp -> (stm, Exp)       (EseqExp)   |expression sequence (s,e) behaves like the comma perator, evaluating the statement s for side effects before evaluating and returning result of expr e
*/


// EXPR
struct A_exp_{
    enum {A_idExp, A_numExp, A_opExp, A_eseqExp} kind;
    union{  struct {string i;} id; // variable i;
            struct {int num; } num; //exp -> num  = should evaluate to num
            struct {A_exp left; A_binop binop; A_exp right;} op; //exp -> exp 
            struct {A_stm stm; A_exp exp;} eseq; //exp -> (stm, exp) 
    }u;
};

struct A_expList_ {
    enum {A_pairExpList, A_lastExp_last} kind;
    union{  struct {A_exp head; A_expList tail;} pair;
            A_exp last;
    }u;
};


//stm:compound
A_stm A_CompoundStm(A_stm stm1, A_stm stm2){

    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_compoundStm;
    s->u.compound.stm1 = stm1;
    s->u.compound.stm2 = stm2;
    return s;
}
//stm:assign
A_stm A_AssignStm(string id, A_exp exp){
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_assignStm;
    s->u.assign.id = id;
    s->u.assign.exp = exp;
    return s;
}
//stm:print
A_stm A_PrintStm(A_expList exps){
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_printStm;
    s->u.print.exps = exps;
    return s;
}

//exp:id
A_exp A_IdExp(string i){
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_idExp;
    e->u.id.i = i;
    return e;
}
//exp:num
A_exp A_NumExp(int num){
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_numExp;
    e->u.num.num = num;
    return e;
}
//exp:op
A_exp A_OpExp(A_exp left, A_binop binop, A_exp right){
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_opExp;
    e->u.op.left = left;
    e->u.op.binop = binop;
    e->u.op.right = right;
    return e;
}
//exp:eseq
A_exp A_EseqExp(A_stm stm, A_exp exp){
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_eseqExp;
    e->u.eseq.stm = stm;
    e->u.eseq.exp = exp;
    return e;
}
//explist:pair
A_expList A_PairExpList(A_exp head, A_expList tail){
    A_expList eL = checked_malloc(sozeof(*eL));
    eL->kind = A_pairExpList;
    eL->u.pair.head = head;
    eL->u.pair.tail = tail;
    return eL;
}
//explist:pair
A_expList A_LastExp(A_exp head, A_expList tail){
    A_expList eL = checked_malloc(sozeof(*eL));
    eL->kind = A_expList;
    eL->u.pair.head = head;
    eL->u.pair.tail = tail;
    return eL;
}