#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, mi, n;
    cin >> k;
    vector<int> mas;
    for (int i = 0; i < k; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> mi;
            mas.push_back(mi);
        }
    }
    sort(mas.begin(), mas.end());
    for (int val : mas) {
        cout << val << " ";
    }
    return 0;
}