#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

int main(){
    double second, first, x, y;
    double answer = 0.0;
    int a;
    std::cin >> a;
    std::vector<double> A;
    std::vector<double> B;
    double o, k;
    for (int i = 0; i < a; i++){
        std::cin >> o >> k;
        A.push_back(o);
        B.push_back(k);
    }
    for (int i = 1; i < a; i++){
        x = (A[i] + A[i - 1]) / 2;
        y = (B[i] + B[i - 1]) / 2;
        second = std::sqrt(std::pow(A[i] - A[i - 1], 2) + std::pow(B[i] - B[i - 1], 2));
        first = std::pow(x, 2) + std::pow(y, 0.6);
        answer += (second * first);
    }
    std::cout << std::fixed << std::setprecision(2) << answer << std::endl;
}