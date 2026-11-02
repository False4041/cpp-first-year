#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // Explicit header for greater<int>.
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i += 2) {
        v[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}
