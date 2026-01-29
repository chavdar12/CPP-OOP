#include <iostream>
#include <string>
#include <vector>

#include "Parser.h"
#include "PrintUtils.h"

class Song
{
    std::string name_;
    int length_seconds_;

public:
    Song()
    {
    }

    Song(std::string name, int length_seconds) : name_(name), length_seconds_(length_seconds)
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

std::ostream& operator<<(std::ostream& out, const Song& s)
{
    return out << s.getName() << " " << s.getLengthSeconds();
}

std::istream& operator>>(std::istream& in, Song& s)
{
    std::string name;
    int length;
    in >> name >> length;

    s = Song(name, length);
    return in;
}

int main()
{
    char type;
    std::cin >> type;
    std::cin.ignore();
    std::string stopLine;
    std::getline(std::cin, stopLine);

    if (type == 'i')
    {
        Parser<int> p(std::cin, stopLine);
        int n;
        std::vector<int> numbers;
        while (p.readNext(n))
        {
            numbers.push_back(n);
        }
        print_vector(numbers);
    }
    else if (type == 'w')
    {
        Parser<std::string> p(std::cin, stopLine);
        std::string w;
        std::vector<std::string> words;
        while (p.readNext(w))
        {
            words.push_back(w);
        }
        print_vector(words);
    }
    else if (type == 's')
    {
        Parser<Song> p(std::cin, stopLine);
        Song s;
        std::vector<Song> songs;
        while (p.readNext(s))
        {
            songs.push_back(s);
        }
        print_vector(songs);
    }
    else
    {
        std::cout << "[invalid input]" << std::endl;
    }

    return 0;
}
