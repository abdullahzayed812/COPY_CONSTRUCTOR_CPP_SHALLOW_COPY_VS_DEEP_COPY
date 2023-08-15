#include <iostream>

using namespace std;

/**
  * Copy constructor is a special constructor that called in that cases:
  * 1 - When assign object to anther one.
  * 2 - Pass object to a function without reference.
  * 3 - Return object from function. 
*/

class MyNumber {  
  private:
    int *val1;
    int val2;

  public:
    MyNumber(int x = 3, int y = 5) {
      cout << "Normal Constructor\n";
      val1 = new int;
      *val1 = x;
      val2 = y;
    }

    // Without reference will make compilation error, because it will passed to private function, make infinite recursion.
    MyNumber(const MyNumber &another) {
      cout << "Copy constructor\n";
      val1 = new int;
      *val1 = *another.val1;
      val2 = another.val2;
    }

    ~MyNumber() {
      delete val1;
    }

    void printValueAndAddress() {
      cout << "Val1: " << *val1 << "\t" << val1 << "\n";
      cout << "Val2: " << val2 << "\t" << &val2 << "\n";
      cout << "\n";
    }
};

void copyObj(MyNumber c) {
  // Will call copy constructor.
  cout << "this function will call copy constructor\n";
}

MyNumber copyObject(MyNumber c) {
  // Will call copy constructor
  return c;
}

int main() {
  MyNumber a;
  // Assign object to anther one.
  MyNumber b(a);
  // Assign object to anther one.
  MyNumber d = b;

  a.printValueAndAddress();
  b.printValueAndAddress();

  copyObj(a);
  copyObject(a);

  return 0;
}