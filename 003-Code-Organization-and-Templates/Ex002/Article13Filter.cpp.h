#pragma once
#include <utility>

#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted) {
    this->copyrighted = std::move(copyrighted);
}

bool Article13Filter::block_if_copyrighted(std::string s) {
    if (is_copyrighted(s)) {
        blocked.push_back(s);
        return true;
    }
    return false;
}

bool Article13Filter::is_copyrighted(const std::string &s) const {
    return copyrighted.count(s) > 0;
}

std::vector<std::string> Article13Filter::get_blocked() {
    return blocked;
}
