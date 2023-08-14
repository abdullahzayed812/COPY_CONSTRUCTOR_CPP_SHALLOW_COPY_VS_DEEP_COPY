#include <iostream>

using namespace std;

/**
  * Shallow Copy VS Deep Copy.
  * Shallow Copy => Same object points to the same memory block.
  * Deep Copy => Make more handling for ensure every object has it's own copy.
  *
  * when we assign object that has a pointer to another one it make,
  * two object will seen the same memory space val1 => Shallow Copy
*/

class MyNumber {
  private:
    int *val1;
    int val2;
  public:
    MyNumber(int x = 3, int y = 5) {
      val1 = new int;
      *val1 = x;
      val2 = y;
    }
    ~MyNumber() {
      // When first object call destructor another will fail, because the pointer will not be exist.
      delete val1;
    }

    void printValueAndAddress() {
      cout << "Value of val1 is: " << *val1 << " and it's address is: " << val1 << "\n";
      cout << "Value of val2 is: " << val2 << " and it's address is: " << &val1 << "\n";
      cout << endl;
    }
};

int main() {
  MyNumber a;
  MyNumber b(10, 20);

  a.printValueAndAddress();
  b.printValueAndAddress();

  b = a;

  // Make shallow copy, same object points to same memory
  b.printValueAndAddress();

  return 0;
}