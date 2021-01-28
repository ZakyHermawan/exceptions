#include <iostream>
#include <exception>

using std::cout;
using std::endl;
using std::cin;

class Fraction
{
private:
    int m_numerator, m_denominator;

public:
    Fraction(int num, int den) : m_numerator{ num }, m_denominator{ den }
    {
        if (den == 0) {
            throw std::runtime_error("Invalid denominator");
        }
    }

    void show() {
        cout << m_numerator << " / " << m_denominator << endl;
        return;
    }
};

int main() {
    int numerator, denominator;
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;

    try {
        Fraction f(numerator, denominator);
        f.show();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << endl;
    }

    return 0;
}