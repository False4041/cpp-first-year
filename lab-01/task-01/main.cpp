#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("a.txt");
    double x, sum = 0;
    int count = 0;
    while (fin >> x) {
        if (x > 0) {
            count++;
            sum += x;
        }
    }
    cout << "quantity positive: " << count << endl;
    cout << "sum positive: " << sum << endl;
    return 0;
}
