#pragma once
#include <vector>
#include <cassert>
#include "originator.hpp"
class caretake {
private:
    int max_size_ = 10;
    std::vector<memento*>mementos_;
    originator* originator_ = nullptr;
public:
    caretake(originator* p, int max_size = 10) {
        originator_ = p;
        max_size_ = max_size;
        assert(originator_);
    }
    virtual ~caretake() {
        for (auto p : mementos_) {
            if (p) {
                delete p;
                p = nullptr;
            }
        }
    }
public:
    void backup() {
        if (mementos_.size() >= max_size_) {
            printf("keep mementos up to the max size:%d\n", max_size_);
            return;
        }
        mementos_.push_back(originator_->make_snapshot());
    }
    void undo() {
        if (0 == mementos_.size()) {
            return;
        }
        auto p = mementos_.back();
        mementos_.pop_back();
        if (p) {
            originator_->restore_from_snapshot(p);
            delete p;
        }
    }
};