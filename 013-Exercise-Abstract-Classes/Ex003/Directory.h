#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <list>
#include <memory>
#include <string>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

class Directory : public FileSystemObject, public FileSystemObjectsContainer
{
    std::list<std::shared_ptr<FileSystemObject>> nestedObj;

public:
    Directory(std::string name) : FileSystemObject(name)
    {
    }

    size_t getSize() const override
    {
        size_t size = 0;
        for (auto objPtr : nestedObj)
        {
            size += objPtr->getSize();
        }
        return size;
    }

    void add(const std::shared_ptr<FileSystemObject>& obj) override
    {
        nestedObj.push_back(obj);
    }
};

#endif
