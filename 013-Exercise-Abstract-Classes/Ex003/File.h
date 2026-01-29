#ifndef FILE_H
#define FILE_H

#include <cstdlib>
#include <string>

#include "ByteContainer.h"
#include "FileSystemObject.h"

class File : public ByteContainer, public FileSystemObject
{
    std::string bytes;

public:
    File(std::string name, std::string bytes) : FileSystemObject(name), bytes(bytes)
    {
    }

    std::string getBytes() const override { return bytes; };
    size_t getSize() const override { return this->getBytes().size(); };
};

#endif
