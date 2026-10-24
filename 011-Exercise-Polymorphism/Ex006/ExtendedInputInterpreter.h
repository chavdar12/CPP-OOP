#pragma once

#include "InputInterpreter.h"
#include "DivisionOperation.h"
#include "MemorySave.h"
#include "MemoryRecall.h"

class ExtendedInputInterpreter : public InputInterpreter {
public:
    ExtendedInputInterpreter(CalculationEngine &engine) : InputInterpreter(engine) {
    }

    std::shared_ptr<Operation> getOperation(std::string operation) override {
        if (operation == "/") {
            return std::make_shared<DivisionOperation>();
        }

        if (operation == "ms") {
            return mMemorySave;
        }

        if (operation == "mr") {
            return std::make_shared<MemoryRecallOperation>(mMemorySave);
        }

        return InputInterpreter::getOperation(operation);
    }

private:
    // created up front so "mr" before any "ms" doesn't dereference null
    std::shared_ptr<MemorySaveOperation> mMemorySave = std::make_shared<MemorySaveOperation>();
};
