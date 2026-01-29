#ifndef IN_H
#define IN_H

#include "CommandInterface.h"
#include "AdvancedCommandInterface.h"

#include <memory>
#include <string>

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text)
{
    auto interface = std::make_shared<AdvancedCommandInterface>(text);
    interface->init();
    return interface;
}

#endif
