#pragma once
#include <utility>

#include "Article13Filter.h"

inline Article13Filter::Article13Filter(std::set<std::string> copyrighted)
{
    this->copyrighted = std::move(copyrighted);
}

inline bool Article13Filter::block_if_copyrighted(std::string s)
{
    if (is_copyrighted(s))
    {
        blocked.push_back(s);
        return true;
    }
    return false;
}

inline bool Article13Filter::is_copyrighted(const std::string& s) const
{
    return copyrighted.count(s) > 0;
}

inline std::vector<std::string> Article13Filter::get_blocked()
{
    return blocked;
}
