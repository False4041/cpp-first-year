#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Auto {
    string marka;
    string cvet;
    string ser_num;
    string reg_num;
    int god_vypuska;
    int god_tehosmotra;
    double cena;
};

int main() {
    ifstream fin("a.txt");
    ofstream fout("b.txt");
    Auto a;
    char sep;
    int tekushiy_god = 2026;
    while (getline(fin, a.marka, ';')) {
        getline(fin, a.cvet, ';');
        getline(fin, a.ser_num, ';');
        getline(fin, a.reg_num, ';');
        fin >> a.god_vypuska;
        fin.get(sep);
        fin >> a.god_tehosmotra;
        fin.get(sep);
        fin >> a.cena;
        fin.ignore(1000, '\n');
        if (tekushiy_god - a.god_vypuska > 2) {
            fout << "Marka: " << a.marka << endl;
            fout << "Cvet: " << a.cvet << endl;
            fout << "Seriyniy nomer: " << a.ser_num << endl;
            fout << "Registracionniy nomer: " << a.reg_num << endl;
            fout << "God vypuska: " << a.god_vypuska << endl;
            fout << "God tehosmotra: " << a.god_tehosmotra << endl;
            fout << "Cena: " << a.cena << endl;
            fout << endl;
        }
    }
    fin.close();
    // The report screenshot ends after fin.close().
    fout.close();
    return 0;
}
