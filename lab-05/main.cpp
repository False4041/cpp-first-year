#include <iostream>
#include <stdexcept>
using namespace std;

class Mass {
private:
    double kg;
public:
    Mass() {
        kg = 0;
    }
    Mass(double value) {
        kg = value;
    }
    Mass(const Mass& other) {
        kg = other.kg;
    }
    ~Mass() {}
    double getKg() const {
        return kg;
    }
    void setKg(double value) {
        kg = value;
    }
    double toGrams() const {
        return kg * 1000;
    }
    Mass operator+(const Mass& other) const {
        return Mass(kg + other.kg);
    }
    Mass operator-(const Mass& other) const {
        return Mass(kg - other.kg);
    }
    Mass operator*(double number) const {
        return Mass(kg * number);
    }
    Mass operator/(double number) const {
        if (number == 0) {
            throw runtime_error("Division by zero");
        }
        return Mass(kg / number);
    }
    bool operator==(const Mass& other) const {
        return kg == other.kg;
    }
    bool operator!=(const Mass& other) const {
        return kg != other.kg;
    }
    friend ostream& operator<<(ostream& out, const Mass& m) {
        out << m.kg << " kg";
        return out;
    }
    friend istream& operator>>(istream& in, Mass& m) {
        in >> m.kg;
        return in;
    }
};

int main() {
    Mass a;
    a.setKg(2);
    Mass b(3);
    Mass c(b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "a (kg) = " << a.getKg() << endl;
    cout << "a (grams) = " << a.toGrams() << endl;
    cout << "a + b = " << a + b << endl;
    cout << "b - a = " << b - a << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "b / 2 = " << b / 2 << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    Mass d;
    cout << "Enter mass in kg: ";
    cin >> d;
    cout << "d = " << d << endl;
    cout << "d (grams) = " << d.toGrams() << endl;
    return 0;
}
