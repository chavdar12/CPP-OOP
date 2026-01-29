#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
    std::string name_;
    int length_seconds_;

public:
    Song()
    {
    }

    Song(std::string name, const int length_seconds) : name_(std::move(name)), length_seconds_(length_seconds)
    {
    }

    std::string getName() const
    {
        return this->name_;
    }

    int getLengthSeconds() const
    {
        return this->length_seconds_;
    }
};

// NOTE: this is intentional - it defines an ordering by name, so that you can't use an operator overload to order the Song objects in the task. Think of a different approach
inline bool operator<(const Song& thiz, const Song& other)
{
    return thiz.getLengthSeconds() < other.getLengthSeconds();
}


#endif // !SONG_H
