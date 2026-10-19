#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("a.txt");
    int x, pos = 1;
    int count = 0;
    double sum = 0;
    while (fin >> x) {
        if (pos % 2 != 0 && x > 0) {
            sum += x;
            count++;
        }
        pos++;
    }
    if (count > 0)
        cout << "Average = " << sum / count;
    else
        cout << "No positive numbers at odd positions";
    return 0;
}
