#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class Member {
public:
  Member() { cout << "Member created" << endl; }

  ~Member() { cout << "Member destroyed" << endl; }
};

class A {
private:
  int m_x;
  Member m_member;

public:
  A(int x) : m_x{0} {
    cout << "A is created" << endl;
    if (x <= 0)
      throw 1;
  }

  ~A() { cout << "A is destroyed" << endl; }
};

int main() {
  try {
    A a{0};
  } catch (...) {
    cerr << "Error" << endl;
  }
}