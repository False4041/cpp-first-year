#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("a2.txt");
    int x;
    int count0 = 0, count1 = 0;
    while (fin >> x) {
        if (x == 0) count0++;
        if (x == 1) count1++;
    }
    if (count0 > count1)
        cout << "More elements are equal to 0";
    else if (count1 > count0)
        cout << "More elements are equal to 1";
    else
        cout << "Counts are equal";
    return 0;
}
