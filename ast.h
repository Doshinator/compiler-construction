/* Doshinator Feb-14-2018 */
// id
typedef char *string;
//statement
typedef struct A_stm_ *A_stm;
//expr
typedef struct A_exp_ *A_exp;
//exp list
typedef struct A_expList_ *A_expList;
//bin op
typdef enum {A_plus, A_minus, A_times, A_divide} A_binop;


//struct union stm
A_stm A_CompoundStm(A_stm stm1, A_stm stm2);
A_stm A_AssignStm(string id, A_exp exp);
A_stm A_PrintStm(A_expList exps);

//struct union exp
A_exp A_IdExp(string i);
A_exp A_NumExp(int num);
A_exp A_OpExp(A_exp exp1, A_binop binop, A_exp exp2);
A_exp A_EseqExp(A_stm stm, A_exp exp);

void *checked_malloc(int len);