#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class ArrayException {
private:
  std::string m_error;

public:
  ArrayException(std::string err) : m_error{err} {}

  const char *getErr() const { return m_error.c_str(); }
};

class IntArray {
private:
  int m_data[3];

public:
  IntArray() = default;

  int getLength() const { return 3; }

  int &operator[](const int index) {
    if (index < 0 || index >= getLength())
      throw ArrayException("Invalid index");
    return m_data[index];
  }
};

int main() {
  IntArray arr;
  try {
    int val{arr[5]};
  } catch (const ArrayException &exception) {
    cerr << "Array exception occured (" << exception.getErr() << ")" << endl;
  }
}