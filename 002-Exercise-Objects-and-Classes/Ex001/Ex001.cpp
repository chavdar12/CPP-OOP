#include <deque>
#include <iostream>
#include <sstream>

int main()
{
    std::deque<std::string> words;
    std::string buffer;
    getline(std::cin, buffer);
    std::istringstream iss(buffer);

    std::string word;
    while (iss >> word)
    {
        words.push_back(word);
    }

    int shifts;
    std::cin >> shifts;

    for (int i = 0; i < shifts; i++)
    {
        std::string lastWord = words.back();
        words.pop_back();
        words.push_front(lastWord);
    }

    for (const auto& word : words)
    {
        std::cout << word << '\n';
    }
}
