We use a tree representation to describe the grammar.
- GRAMMAR
stm
exp
exprList
id
num


- Rules

each stm is a stm
each exp is an exp
s1;s2 executes statement s1, then statement s2
i :=e evaluates the expression e, then stores result in variable i
print(e1 ... en) prints value of all expressions from left to right
Identifier expression, like i, yields current content of variable i
num evaluates to named integer
operator expression e1 op e2 evaluates e1, then e2, then applies binop
expression sequence (s,e) behaves like the comma perator, evaluating the statement s for side effects before evaluating and returning result of expr e

- What to do
translate grammar directly into data structure definition

- For each grammar Rule
there is one constructor that belongs to the union for lhs synbol.
constructor names are indicated on the rhs of grammar 1.3.


union{
stm -> stm1 ; stm2      (compoundStm)
stm -> id ;= Expr       (assignStm)
stm -> print(ExprList)  (printStm)
}

union {
    Exp -> id           (IdExp)
    Exp -> num          (NumExp)
    Exp -> Exp Binop Exp    (OpExp)
    Exp -> (stm, Exp)   (EseqExp)
}



