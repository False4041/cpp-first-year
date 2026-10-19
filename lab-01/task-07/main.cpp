#include <iostream>
#include <fstream>
using namespace std;

const int MAXK = 10;
const int MAXL = 10;
const int MAXM = 10;
const int MAXN = 10;

int main() {
    ifstream fin1("f1.txt");
    ifstream fin2("f2.txt");
    ofstream fout("f3.txt");
    if (!fin1 || !fin2 || !fout) {
        cout << "File error";
        return 1;
    }
    int k, l, m, n;
    int a[MAXK][MAXM][MAXN];
    int b[MAXL][MAXM][MAXN];
    fin1 >> k >> m >> n;
    for (int p = 0; p < k; p++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fin1 >> a[p][i][j];
            }
        }
    }
    int m2, n2;
    fin2 >> l >> m2 >> n2;
    for (int p = 0; p < l; p++) {
        for (int i = 0; i < m2; i++) {
            for (int j = 0; j < n2; j++) {
                fin2 >> b[p][i][j];
            }
        }
    }
    int c1 = 0;
    int c2 = 0;
    while (c1 < k && c2 < l) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = a[c1][i][j];
                a[c1][i][j] = b[c2][i][j];
                b[c2][i][j] = temp;
            }
        }
        c1 += 2;
        c2 += 2;
    }
    cout << "First file after swap:" << endl;
    for (int p = 0; p < k; p++) {
        cout << "Matrix " << p + 1 << ":" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[p][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Second file after swap:" << endl;
    for (int p = 0; p < l; p++) {
        cout << "Matrix " << p << ":" << endl;
        for (int i = 0; i < m2; i++) {
            for (int j = 0; j < n2; j++) {
                cout << b[p][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    if (k > l) {
        for (int p = l; p < k; p++) {
            fout << "Matrix from first file " << p + 1 << ":" << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    fout << a[p][i][j] << " ";
                }
                fout << endl;
            }
            fout << endl;
        }
    } else if (l > k) {
        for (int p = k; p < l; p++) {
            fout << "Matrix from second file " << p << ":" << endl;
            for (int i = 0; i < m2; i++) {
                for (int j = 0; j < n2; j++) {
                    fout << b[p][i][j] << " ";
                }
                fout << endl;
            }
            fout << endl;
        }
    }
    return 0;
}
