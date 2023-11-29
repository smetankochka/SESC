#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> mas1(n);
    std::vector<int> mas2(m);
    for (int i = 0; i < n; i++) {std::cin >> mas1[i];}
    for (int i = 0; i < m; i++) {std::cin >> mas2[i];}
    int ans = 1e9, ansl = 0, ansr = 0, p1 = 0, p2 = 0;
    while (p1 < n - 1 || p2 < m - 1) {
        if (p1 == n - 1) {
            p2++;
        } else if (p2 == m - 1) {
            p1++;
        } else if (mas1[p1] < mas2[p2]) {
            p1++;
        } else {
            p2++;
        }
        if (abs(mas1[p1] - mas2[p2]) < ans) {
            ans = abs(mas1[p1] - mas2[p2]);
            ansl = p1;
            ansr = p2;
        }
    }
    int ansf = mas1[ansl] < mas2[ansr] ? mas1[ansl] : mas2[ansr];
    int anss = mas1[ansl] + mas2[ansr] - ansf;
    std::cout << ansf << " " << anss << "\n";
    return 0;
}