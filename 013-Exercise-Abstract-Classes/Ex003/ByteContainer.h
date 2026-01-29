#ifndef BYTECONTAINER_H
#define BYTECONTAINER_H

#include <string>

class ByteContainer
{
public:
    virtual std::string getBytes() const = 0;

    virtual ~ByteContainer()
    {
    }
};

#endif
