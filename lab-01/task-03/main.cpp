#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("a.txt");
    ofstream fout("b.txt");
    char ch;
    while (fin.get(ch)) {
        if (isalpha((unsigned char)ch)) {
            fout << ch;
        }
    }
    fin.close();
    fout.close();
    cout << "Done";
    return 0;
}
