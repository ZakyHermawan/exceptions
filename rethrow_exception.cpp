#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base() = default;
    virtual void print() { cout << "Base"; }
};

class Derived : public Base
{
public:
    Derived() = default;
    virtual void print() { cout << "Derived"; }
};


int main() {
    try {
        try {
            throw Derived{};
        }
        catch (Base& b) {
            cout << "Caught base, which is actually ";
            b.print();
            cout << endl;
            throw;
        }
    }
    catch (Base& b) {
        cout << "Caught base, which is actually ";
        b.print();
        cout << endl;

    }


    return 0;
}