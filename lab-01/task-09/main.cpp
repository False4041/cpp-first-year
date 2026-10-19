// Headers, main and the array declaration are above the visible screenshot.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    double a[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    ofstream fout("a.bin", ios::binary);
    for (int i = 0; i < 5; i++) {
        fout.write((char*)a[i], 5 * sizeof(double));
    }
    fout.close();
    cout << "Before:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    ifstream fin("a.bin", ios::binary);
    double b[5][5];
    for (int i = 0; i < 5; i++) {
        fin.read((char*)b[i], 5 * sizeof(double));
    }
    fin.close();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            b[i][j] = b[i][j] * 1.5;
        }
    }
    ofstream fout2("a.bin", ios::binary);
    for (int i = 0; i < 5; i++) {
        fout2.write((char*)b[i], 5 * sizeof(double));
    }
    fout2.close();
    cout << endl << "After:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    // End of main restored beyond the screenshot.
    return 0;
}
