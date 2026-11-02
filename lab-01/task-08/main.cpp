#include <iostream>
#include <fstream>
using namespace std;

struct Jazz {
    char ispolnitel[50];
    char album[50];
    int tirazh;
    int god;
    double cena;
};

int main() {
    Jazz a[4] = {
        {"MilesDavis", "KindOfBlue", 1500, 2026, 60},
        {"JohnColtrane", "BlueTrain", 900, 2026, 55},
        {"EllaFitzgerald", "JazzLove", 2000, 2025, 70},
        {"LouisArmstrong", "GoldenHits", 3000, 2026, 45}
    };
    ofstream fout("jazz.dat", ios::binary);
    if (!fout) {
        cout << "File error";
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        fout.write((char*)&a[i], sizeof(Jazz));
    }
    fout.close();
    ifstream fin("jazz.dat", ios::binary);
    if (!fin) {
        cout << "File error";
        return 1;
    }
    Jazz x;
    int currentYear = 2026;
    while (fin.read((char*)&x, sizeof(Jazz))) {
        if (x.god == currentYear && x.tirazh > 1000 && x.cena >= 50) {
            cout << "Ispolnitel: " << x.ispolnitel << endl;
            cout << "Album: " << x.album << endl;
            cout << "Tirazh: " << x.tirazh << endl;
            cout << "God: " << x.god << endl;
            cout << "Cena: " << x.cena << endl;
            cout << endl;
        }
    }
    // End of main restored beyond the screenshot.
    return 0;
}
