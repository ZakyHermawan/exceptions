#include <exception> // for std::exception
#include <iostream>
#include <string>
#include <string_view>

class ArrayException : public std::exception
{
private:
    std::string m_error{};

public:
    ArrayException(std::string_view error)
        : m_error{ error }
    {
    }

    const char* what() const noexcept override { return m_error.c_str(); }
};

class IntArray
{
private:

    int m_data[3];
public:
    IntArray() {}

    int getLength() const { return 3; }

    int& operator[](const int index)
    {
        if (index < 0 || index >= getLength())
            throw ArrayException("Invalid index");

        return m_data[index];
    }

};

int main()
{
    IntArray array;

    try
    {
        int value{ array[5] };
    }
    catch (const ArrayException& exception) // derived catch blocks go first
    {
        std::cerr << "An array exception occurred (" << exception.what() << ")\n";
    }
    catch (const std::exception& exception) // not executed
    {
        std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
    }
}