#include "Matrix.h"


Matrix& Matrix::operator=(const std::vector<std::vector<int>>& data)
{
    this->_data = data;
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    for (unsigned i = 0; (i < this->_data.size() && i < other._data.size()); i++)
    {
        for (unsigned j = 0; (j < this->_data[i].size() && j < other._data[i].size()); j++)
        {
            this->_data[i][j] += other._data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    for (unsigned i = 0; (i < this->_data.size() && i < other._data.size()); i++)
    {
        for (unsigned j = 0; (j < this->_data[i].size() && j < other._data[i].size()); j++)
        {
            this->_data[i][j] -= other._data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    for (unsigned i = 0; (i < this->_data.size() && i < other._data.size()); i++)
    {
        for (unsigned j = 0; (j < this->_data[i].size() && j < other._data[i].size()); j++)
        {
            this->_data[i][j] *= other._data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(const Matrix& other)
{
    for (unsigned i = 0; (i < this->_data.size() && i < other._data.size()); i++)
    {
        for (unsigned j = 0; (j < this->_data[i].size() && j < other._data[i].size()); j++)
        {
            if (other._data[i][j] != 0)
            {
                this->_data[i][j] /= other._data[i][j];
            }
            else
            {
                this->_data[i][j] = 0;
            }
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, const Matrix& matrix)
{
    for (unsigned i = 0; i < matrix._data.size(); i++)
    {
        for (unsigned j = 0; j < matrix._data[i].size(); j++)
        {
            o << matrix._data[i][j] << ' ';
        }
        o << std::endl;
    }
    return o;
}
