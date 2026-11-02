#include <iostream>
using namespace std;

class IntVector {
private:
    int* data;
    int size;
public:
    IntVector() {
        data = nullptr;
        size = 0;
    }
    IntVector(int n) {
        if (n < 0) n = 0;
        size = n;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }
    ~IntVector() {
        delete[] data;
    }
    void pushFront(int value) {
        int* temp = new int[size + 1];
        temp[0] = value;
        for (int i = 0; i < size; i++) {
            temp[i + 1] = data[i];
        }
        delete[] data;
        data = temp;
        size++;
    }
    void popFront() {
        if (size == 0) return;
        for (int i = 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        size--;
    }
    int getSize() {
        return size;
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    IntVector a;
    a.pushFront(10);
    a.pushFront(20);
    a.pushFront(30);
    cout << "Array: ";
    a.print();
    cout << "Size: " << a.getSize() << endl;
    a.popFront();
    cout << "After popFront: ";
    a.print();
    IntVector b(3);
    cout << "Second array: ";
    b.print();
    return 0;
}
