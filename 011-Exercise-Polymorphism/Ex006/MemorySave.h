#ifndef MEMORY_SAVE_H
#define MEMORY_SAVE_H

#include <stack>
#include "Operation.h"

class MemorySaveOperation : public Operation {
public:
    void addOperand(int operand) override {
        this->mOperands.push(operand);
        this->mJustSaved = true;
    }

    // completes right after saving, so the engine stops feeding numbers into memory
    bool isCompleted() override {
        return mJustSaved;
    }

    // the engine reads this once on completion: saving keeps the current result unchanged
    int getResult() override {
        mJustSaved = false;
        return mOperands.top();
    }

    int recall() {
        if (mOperands.empty()) {
            return 0;
        }
        const int result = mOperands.top();
        mOperands.pop();
        return result;
    }

private:
    std::stack<int> mOperands;
    bool mJustSaved = false;
};

#endif //MEMORY_SAVE_H
