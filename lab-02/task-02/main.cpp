#include <iostream>
#include <vector>
using namespace std;

void part(vector<int> v, vector<int>& half, vector<int>& third) {
    int n = v.size();
    for (int i = 0; i < n / 2; i++) {
        half.push_back(v[i]);
    }
    for (int i = n / 3; i < 2 * n / 3; i++) {
        third.push_back(v[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> half;
    vector<int> third;
    part(v, half, third);
    double sum1 = 0;
    for (int i = 0; i < half.size(); i++) {
        sum1 += half[i];
    }
    double average1 = sum1 / half.size();
    double sum2 = 0;
    for (int i = 0; i < third.size(); i++) {
        sum2 += third[i];
    }
    double average2 = sum2 / third.size();
    int max17 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 17 == 0 && v[i] > max17) {
            max17 = v[i];
        }
    }
    int count1 = 0;
    for (int i = 0; i < half.size(); i++) {
        for (int j = i + 1; j < half.size(); j++) {
            if (half[i] + half[j] > max17) {
                count1++;
            }
        }
    }
    int count2 = 0;
    for (int i = 0; i < third.size(); i++) {
        for (int j = i + 1; j < third.size(); j++) {
            if (third[i] + third[j] > max17) {
                count2++;
            }
        }
    }
    cout << "Average first half: " << average1 << endl;
    cout << "Average middle third: " << average2 << endl;
    cout << "Pairs first half: " << count1 << endl;
    cout << "Pairs middle third: " << count2 << endl;
    return 0;
}
