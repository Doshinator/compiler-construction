#include <functional>

static int test_passed = 0;

static void summary(){
    cout << test_passed << " test(s) passed!" << endl;
}

static void check(string which, std::function<(void)int> te, int expected){
    try{
        int actual = atio(te->toString());
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
    check("eval", [] -> eval(e), ans);
}


/*
static int test_passed = 0;

static void summary(){
    cout << test_passed << " test(s) passed!" << endl;
}

static void check(string which, std::function<void(int)> te, int expected){
    try{
        int actual = te.get();
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
    check("eval",[](){return eval(e)}, ans);
}


*/