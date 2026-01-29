#ifndef MIN_BY_H
#define MIN_BY_H
// Place your code here 

/*
hear the rime of the ancient mariner see his eyes as he stops one of 
3
*/

#include <string>
#include <algorithm>

const std::string minBy(const std::vector<std::string>& values,
                        bool (*lessFunction)(const std::string& a, const std::string& b))
{
    //std::sort(values.begin(), values.end(), lessFunction); doesn't not find the first largest/.../...;

    int index = 1;
    std::string found = values[0];
    for (; index < values.size(); index++)
    {
        if (lessFunction(values[index], found))
        {
            found = values[index];
        }
    }
    return found;
}


#endif // !MIN_BY_H
