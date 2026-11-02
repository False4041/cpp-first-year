#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("f.txt");
    ofstream fout("result.txt");
    char c1, c2;
    fin.get(c1);
    fin.get(c2);
    if (isdigit(c1) && isdigit(c2)) {
        int num = (c1 - '0') * 10 + (c2 - '0');
        fout << "First two symbols are digits" << endl;
        fout << "Number = " << num << endl;
        if (num % 2 == 0)
            fout << "Number is even" << endl;
        else
            fout << "Number is odd" << endl;
    } else {
        fout << "First two symbols are not digits" << endl;
    }
    fin.close();
    fout.close();
    cout << "Done";
    return 0;
}
