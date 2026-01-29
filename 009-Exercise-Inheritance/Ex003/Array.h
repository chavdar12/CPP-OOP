#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array
{
private:
    T* data;
    size_t size;

public:
    // Default constructor
    Array(size_t size = 0) : size(size)
    {
        if (size > 0)
        {
            data = new T[size];
        }
        else
        {
            data = nullptr;
        }
    }

    // Destructor
    ~Array()
    {
        delete[] data;
    }

    // Copy constructor
    Array(const Array& other) : size(other.size)
    {
        if (size > 0)
        {
            data = new T[size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        else
        {
            data = nullptr;
        }
    }

    // Assignment operator
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            if (size > 0)
            {
                data = new T[size];
                for (size_t i = 0; i < size; i++)
                {
                    data[i] = other.data[i];
                }
            }
            else
            {
                data = nullptr;
            }
        }
        return *this;
    }

    // Indexing operator
    T& operator[](size_t index)
    {
        return data[index];
    }

    const T& operator[](size_t index) const
    {
        return data[index];
    }

    // Get the size of the array
    size_t getSize() const
    {
        return size;
    }

    // Iterator support
    T* begin()
    {
        return data;
    }

    const T* begin() const
    {
        return data;
    }

    T* end()
    {
        return data + size;
    }

    const T* end() const
    {
        return data + size;
    }
};

#endif // ARRAY_H
