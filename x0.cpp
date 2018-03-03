
class X0Arg {
    public:
        virtual string toString() = 0;
};

//x0 const
class X0AInt : public X0Arg{
    public:
        int n;
        X0AInt(int n) {this->n = n;}
        string toString(){return to_string(n);}
};
//x0 reg 
class X0AReg : public X0Arg{
    public:
        Registers *reg;
        X0AReg(Registers *reg) {this->reg = reg;}
        virtual string toString() = 0;
};

//x0 offset / deref
// class offset { something something };




//x0 registers
class Registers : public X0Reg{
    public:
        virtual toString() = 0;
};

class RSP : public Registers{
    public:
        int n;
        RSP(int n) {this->n = n;}
        string toString() {return to_string(n)+"(%rsp)";}

};
class RBP : public Registers{
    public:
        int n;
        RBP(int n) {this->n = n;}
        string toString() {return to_string(n)"(%rbp)";}

};
class RAX : public Registers{
    public:
        int n;
        RAX(int n) {this->n = n;}
        string toString() {return to_string(n)"(%rax)";}

};
class RBX : public Registers{
    public:
        int n;
        RBX(int n) {this->n = n;}
        string toString() {return to_string(n);}

};
class RCX : public Registers{
    public:
        int n;
        RDI(int n) {this->n = n;}
        string toString() {return to_string(n);}

};
class RDX : public Registers{
    public:
        public:
        int n;
        RCX(int n) {this->n = n;}
        string toString() {return to_string(n);}

};
class RSI : public Registers{
    public:
        int n;
        RSI(int n) {this->n = n;}
        string toString() {return to_string(n);}

};
class RDI : public Registers{
    public:
        int n;
        RDI(int n) {this->n = n;}
        string toString() {return to_string(n);}
};

class R8 : public Registers{
    public:
        int n;
        R8(int n) {this->n = n}
        string toString() {return to_string(n);}
};
class R9 : public Registers{
    public:
        int n;
        R9(int n) {this->n = n}
        string toString() {return to_string(n);}
};
class R10 : public Registers{
    public:
        int n;
        R10(int n) {this->n = n}
        string toString() {return to_string(n);}
};
class R11 : public Registers{
    public:
        int n;
        R11(int n) {this->n = n}
        string toString() {return to_string(n);}
};
class R12 : public Registers{
    public:
        int n;
        R12(int n) {this->n = n}
        string toString() {return to_string(n);}
};
class R13 : public Registers{
    public:
        int n;
        R13(int n) {this->n = n}
        string toString() {return to_string(n);}
};
class R14 : public Registers{
    public:
        int n;
        R14(int n) {this->n = n}
        string toString() {return to_string(n);}
};
class R15 : public Registers{
    public:
        int n;
        R15(int n) {this->n = n}
        string toString() {return to_string(n);}
};




//x0 instructions
class X0Instr{
    public:
        virtual string toString() = 0;
};

class addq : public X0Instr{
    public:
        X0Arg *arg_src, *arg_dst;
        addq(XX0Arg *arg_src, X0Arg *arg_dst) {this->arg_src = arg_src; this->arg_dst = arg_dst;}
        string toString() = {return "addq " + arg_src->toString() + ", " + arg_dst->toString();}
};

class subq : public X0Instr{
    public:
        X0Arg *arg_src, *arg_dst;
        subq(XX0Arg *arg_src, X0Arg *arg_dst) {this->arg_src = arg_src; this->arg_dst = arg_dst;}
        string toString() = {return "subq " + arg_src->toString() + ", " + arg_dst->toString();}
};

class movq : public X0Instr{
    public:
        X0Arg *arg_src, *arg_dst;
        movq(XX0Arg *arg_src, X0Arg *arg_dst) {this->arg_src = arg_src; this->arg_dst = arg_dst;}
        string toString() = {return "movq " + arg_src->toString() + ", " + arg_dst->toString();}
};

class retq : public X0Instr{
    public:
        string toString() {return "retq ";}
};

class negq : public X0Instr{
    public:
        X0Arg *arg;
        negq(X0Arg *arg) {this->arg = arg;}
        string toString() {return "negq " + arg->toString();}
};

class callq : public X0Instr {
    public:
        //callq (label) what is a label???
        string toString() {return "callq " + "implement a label here";} 
};

class pushq : public X0Instr {
    public:
        X0Arg *arg;
        pushq(X0Arg *arg) {this->arg = arg;}
        string toString() {return "pushq " + arg->toString();}
};

class popq : public X0Instr {
    public:
        X0Arg *arg;
        popq(X0Arg *arg) {this->arg = arg;}
        string toString() {return "popq " + arg->toString();}
};

class X0Read : public X0Instr{
    public:
        X0Arg *dst;
        X0Rad(X0Arg *dst){this->dst = dst;}
        string toString() {return "callq_read_int\n     movq %rax, " + dst->toString();}
};


class XProgram {
    public:

};