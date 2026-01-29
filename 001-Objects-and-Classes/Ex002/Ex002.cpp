#include <iostream>
#include <vector>
#include <string>

int main()
{
    constexpr int rows = 10;
    constexpr int cols = 10;

    std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols, '.'));

    for (int row = 0; row < rows; ++row)
    {
        std::string line;
        std::getline(std::cin, line);
        for (int col = 0; col < cols; ++col)
        {
            matrix[row][col] = line[col];
        }
    }

    int time;
    std::cin >> time;

    for (int t = 0; t < time; ++t)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '!')
                {
                    if (i > 0 && matrix[i - 1][j] == '.')
                    {
                        matrix[i - 1][j] = '!';
                    }
                    if (i < rows - 1 && matrix[i + 1][j] == '.')
                    {
                        matrix[i + 1][j] = '!';
                    }
                    if (j > 0 && matrix[i][j - 1] == '.')
                    {
                        matrix[i][j - 1] = '!';
                    }
                    if (j < cols - 1 && matrix[i][j + 1] == '.')
                    {
                        matrix[i][j + 1] = '!';
                    }
                }
            }
        }
    }

    for (const auto& row : matrix)
    {
        for (const char cell : row)
        {
            std::cout << cell;
        }
        std::cout << '\n';
    }

    return 0;
}
