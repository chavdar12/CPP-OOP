#ifndef MEMORY_SAVE_H
#define MEMORY_SAVE_H

#include <stack>
#include "Operation.h"

class MemorySaveOperation : public Operation
{
public:
    void addOperand(int operand) override
    {
        this->mOperands.push(operand);
    }

    bool isCompleted() override
    {
        return false;
    }

    int getResult() override
    {
        const int result = mOperands.top();
        mOperands.pop();
        return result;
    }

private:
    std::stack<int> mOperands;
};

#endif //MEMORY_SAVE_H
