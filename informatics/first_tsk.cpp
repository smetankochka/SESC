#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, count;
    long long sum;
    cin >> n >> m;
    vector<vector<int>> mas1(n, vector<int> (m));
    vector<vector<int>> mas2(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count = 1;
            mas2[i][j] = mas1[i][j];
            if (j - 1 >= 0) {
                mas2[i][j] += mas1[i][j - 1];
                count++;
            }
            if (j - 1 >= 0 && i + 1 < n) {
                mas2[i][j] += mas1[i + 1][j - 1];
                count++;
            }
            if (j - 1 >= 0 && i - 1 >= 0) {
                mas2[i][j] += mas1[i - 1][j - 1];
                count++;
            }
            if (i + 1 < n) {
                mas2[i][j] += mas1[i + 1][j];
                count++;
            }
            if (i - 1 >= 0) {
                mas2[i][j] += mas1[i - 1][j];
                count++;
            }
            if (j + 1 < m) {
                mas2[i][j] += mas1[i][j + 1];
                count++;
            }
            if (j + 1 < m && i + 1 < n) {
                mas2[i][j] += mas1[i + 1][j + 1];
                count++;
            }
            if (j + 1 < m && i - 1 >= 0) {
                mas2[i][j] += mas1[i - 1][j + 1];
                count++;
            }
//            cout << mas2[i][j] << " " << count << "\n";
            mas2[i][j] /= count;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mas2[i][j] << " ";
        }
        cout << "\n";
    }
}