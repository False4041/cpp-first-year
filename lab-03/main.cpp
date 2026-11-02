#include <iostream>
#include <string>
using namespace std;

class Coin {
private:
    int nominal;
    int count;
public:
    Coin() {
        nominal = 0;
        count = 0;
    }
    Coin(int n, int c) {
        nominal = 0;
        count = 0;
        setNominal(n);
        setCount(c);
    }
    Coin(const Coin& other) {
        nominal = other.nominal;
        count = other.count;
    }
    ~Coin() {
        cout << "Object destroyed" << endl;
    }
    void setNominal(int n) {
        if (n >= 0) {
            nominal = n;
        }
    }
    void setCount(int c) {
        if (c >= 0) {
            count = c;
        }
    }
    int getNominal() {
        return nominal;
    }
    int getCount() {
        return count;
    }
    int getTotal() {
        return nominal * count;
    }
    string getInfo() {
        return "Nominal: " + to_string(nominal) +
               ", Count: " + to_string(count);
    }
};

int main() {
    Coin a;
    a.setNominal(5);
    a.setCount(10);
    cout << a.getNominal() << endl;
    cout << a.getCount() << endl;
    cout << a.getTotal() << endl;
    cout << a.getInfo() << endl;
    a.setCount(-5);
    cout << a.getCount() << endl;
    Coin b(10, 4);
    cout << b.getInfo() << endl;
    Coin c(b);
    cout << c.getInfo() << endl;
    return 0;
}
