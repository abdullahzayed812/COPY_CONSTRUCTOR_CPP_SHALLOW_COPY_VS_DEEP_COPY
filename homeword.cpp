#include <iostream>

using namespace std;

class MyVector {
  private:
    int *arr;
    int length;

  public:
    MyVector(int len, int defaultValue = 10) {
      cout << "Calling Normal Constructor\n";
      this -> length = len;
      this -> arr = new int[len];

      for (int i = 0; i < len; i++) {
        this -> arr[i] = defaultValue;
      }
    }

    MyVector(const MyVector &another) {
      cout << "Calling Copy Constructor\n";
      this -> length = another.length;
      this -> arr = new int[length];

      for (int i = 0; i < length; i++) {
        this -> arr[i] = another.arr[i];
      }
    }

    ~MyVector() {
      delete[] this -> arr;
    }
    
    int getItem(int pos) {
      if (pos > this -> length) {
        cout << "out of range\n";
        return -1;
      }
      return this -> arr[pos];
    }

    void setItem(int position, int value = 0) {
      if (position > this -> length) {
        cout << "out of range\n";
        return;
      }
      this -> arr[position] = value;
    }
};

// const int& msg1() {
//   int x = 10;
//   return x;
// }

int main() {
  MyVector v1(10, 12345);
  MyVector v2(v1);

  v2.setItem(1200);

  return 0;
}