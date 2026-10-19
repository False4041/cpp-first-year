// Headers are above the visible screenshot.
#include <iostream>
#include <fstream>
using namespace std;

struct Book {
    char author[40];
    char title[40];
    double price;
    int count;
};

int main() {
    Book a[4] = {
        {"Pushkin", "Dochka", 500, 15},
        {"Tolstoy", "Voyna", 800, 25},
        {"Gogol", "Dushi", 600, 30},
        {"Chekhov", "Rasskazy", 400, 10}
    };
    ofstream fout("book.dat", ios::binary);
    for (int i = 0; i < 4; i++) {
        fout.write((char*)&a[i], sizeof(Book));
    }
    fout.close();
    ifstream fin("book.dat", ios::binary);
    Book b[4];
    for (int i = 0; i < 4; i++) {
        fin.read((char*)&b[i], sizeof(Book));
    }
    fin.close();
    for (int i = 0; i < 4; i++) {
        if (b[i].count > 20) {
            b[i].price = b[i].price * 0.95;
        }
    }
    ofstream fout2("book.dat", ios::binary);
    for (int i = 0; i < 4; i++) {
        fout2.write((char*)&b[i], sizeof(Book));
    }
    fout2.close();
    for (int i = 0; i < 4; i++) {
        cout << "Author: " << b[i].author << endl;
        cout << "Title: " << b[i].title << endl;
        cout << "Price: " << b[i].price << endl;
        cout << "Count: " << b[i].count << endl;
        cout << endl;
    }
    // End of main restored beyond the screenshot.
    return 0;
}
