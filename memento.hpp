#pragma once
class memento {
private:
    int iterm0_;
    int iterm1_;
    int iterm2_;
public:
    void set_iterm(int iterm0, int iterm1, int iterm2) {
        iterm0_ = iterm0;
        iterm1_ = iterm1;
        iterm2_ = iterm2;
    }
    int get_iterm0() const {
        return iterm0_;
    }
    int get_iterm1() const {
        return iterm1_;
    }
    int get_iterm2() const {
        return iterm2_;
    }
};