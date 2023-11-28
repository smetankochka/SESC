#include <iostream>
#include <cmath>
#include <vector>
#include <string>

struct decartpoint {
    double x;    // Координата x
    double y;    // Координата y
};

double degreesToRadians(double degrees) {
    const double pi = 3.14159265358979323846;
    return degrees * (pi / 180.0);
}

decartpoint polarToDeCart(double r, double theta) {
    decartpoint c;
    theta = degreesToRadians(theta);
    c.x = r * cos(theta);
    c.y = r * sin(theta);
    return c;
}

void NewPoint(std::vector<decartpoint> &points, const int& k) {
    std::string s;
    std::cin >> s;
    if (s == "P"){
        double r, a;
        std::cin >> r >> a;
        points[k] = polarToDeCart(r, a);
    }else{
        points[k].x = std::stoi(s);
        std::cin >> points[k].y;
    }
}

double distanceBetweenPoints(const decartpoint& p1, const decartpoint& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double spacing(std::vector<decartpoint> &points, const int& m) {
    double dist = 0;
    for (int i = 0; i < m; i++) {
        dist += distanceBetweenPoints(points[i], points[i + 1]);
    }
    return dist;
}

int main() {
    int n, m;
    std::cout << "Enter the number of curves: \n";
    std::cin >> n;
    while (n--) {
        std::cout << "Enter the number of points of the new curve: \n";
        std::cin >> m;
        std::vector<decartpoint> points(m);
        for (int i = 0; i < m; i++) {
            std::cout << "Enter the coordinates: \n";
            NewPoint(points, i);
        }
        std::cout << "Distance: " << spacing(points, m - 1) << "\n";
    }
    return 0;
}