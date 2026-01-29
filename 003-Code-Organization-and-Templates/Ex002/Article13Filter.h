#ifndef ARTICLE_13_FILTER_H
#define ARTICLE_13_FILTER_H

#include <string>
#include <vector>
#include <set>

class Article13Filter
{
private:
    std::set<std::string> copyrighted;
    std::vector<std::string> blocked;

public:
    Article13Filter(std::set<std::string> copyrighted);
    bool block_if_copyrighted(std::string s);
    bool is_copyrighted(const std::string& s) const;

    std::vector<std::string> get_blocked();
};

#endif // !ARTICLE_13_FILTER_H
