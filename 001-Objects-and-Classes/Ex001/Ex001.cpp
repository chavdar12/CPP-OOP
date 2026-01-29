#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

int main()
{
    std::vector<std::string> all_words;
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::string word;

    while (iss >> word)
    {
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        all_words.push_back(word);
    }

    char letter;
    std::cin >> letter;
    std::cin.ignore();

    while (letter != '.')
    {
        std::set<std::string> words_to_print;

        for (const auto& original_word : all_words)
        {
            std::string upper_word = original_word;
            std::transform(upper_word.begin(), upper_word.end(), upper_word.begin(), ::toupper);

            if (upper_word.find(std::toupper(letter)) != std::string::npos)
            {
                words_to_print.insert(original_word);
            }
        }

        if (words_to_print.empty())
        {
            std::cout << "---" << std::endl;
        }
        else
        {
            for (const auto& word : words_to_print)
            {
                std::cout << word << " ";
            }
            std::cout << std::endl;
        }

        std::cin >> letter;
        std::cin.ignore();
    }

    return 0;
}
