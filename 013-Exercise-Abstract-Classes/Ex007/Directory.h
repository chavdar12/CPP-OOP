#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <memory>
#include <string>
#include <vector>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

class Directory : public FileSystemObject, public FileSystemObjectsContainer
{
    std::vector<std::shared_ptr<FileSystemObject>> nestedObj;

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

    void remove(std::shared_ptr<FileSystemObject> obj) override
    {
        this->nestedObj.erase(std::find(this->nestedObj.begin(), this->nestedObj.end(), obj));
    }

    std::vector<std::shared_ptr<FileSystemObject>>::const_iterator begin() const override
    {
        return nestedObj.begin();
    }

    std::vector<std::shared_ptr<FileSystemObject>>::const_iterator end() const override
    {
        return nestedObj.end();
    }
};

#endif
