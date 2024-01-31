#pragma once
#include <stdio.h>
#include "memento.hpp"
class caretake;
class originator {
private:
    memento key_iterms_;
public:
    friend class caretake;
    void do_something(int a, int b, int c) {
        key_iterms_.set_iterm(a, b, c);
        printf("set key iterms(%d,%d,%d)!\n", a, b, c);
    }
    void show() {
         printf("key iterms(%d,%d,%d)!\n", key_iterms_.get_iterm0(),
                                           key_iterms_.get_iterm1(),
                                           key_iterms_.get_iterm2());
    }
private:
    memento* make_snapshot() {
        return new memento(key_iterms_);
    }
    void restore_from_snapshot(memento *key_iterms) {
        key_iterms_ = *key_iterms;
    }
};