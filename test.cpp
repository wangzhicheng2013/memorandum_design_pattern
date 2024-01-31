#include "caretake.hpp"
int main() {
    originator r;
    caretake c(&r);
    r.do_something(1, 3, 5);
    r.show();
    c.backup();
    r.do_something(2, 4, 6);
    r.show();
    c.backup();
    r.do_something(10, 100, 1000);
    r.show();
    c.undo();
    r.show();
    
    return 0;
}