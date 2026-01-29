#ifndef WORDS_H
#define WORDS_H

#include <map>
#include <string>

class Word
{
private:
    std::string word;
    static std::map<std::string, size_t> wordCount;

public:
    Word(const std::string& wordStr) : word(wordStr)
    {
        wordCount[wordStr]++;
    }

    Word(const Word& w)
    {
        this->word = w.word;
    }

    const std::string& getWord() const { return this->word; };

    const size_t getCount() const
    {
        int count = wordCount[this->word];
        wordCount[this->word] = 0;
        return count;
    };

    const bool operator<(const Word& other) const
    {
        return this->word < other.word;
    }
};


#endif
