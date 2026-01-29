#ifndef _TYPED_STREAM_H_
#define _TYPED_STREAM_H_

#include <string>
#include <sstream>
#include <vector>

template <typename T>
class TypedStream
{
protected:
    std::string input;
    std::stringstream stream;

public:
    TypedStream(const std::string& input) : input(input), stream{input}
    {
    }

    virtual TypedStream<T>& operator>>(T& item) = 0;

    std::vector<T> readToEnd()
    {
        std::vector<T> result;
        T temp;
        while (*this >> temp)
        {
            result.push_back(temp);
        }
        return result;
    }

    operator bool() const
    {
        return !stream.fail();
    }
};

#endif
