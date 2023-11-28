#include <iostream>
#include <cmath>
#include <vector>
#include <string>

// struct Polar_Point {
//     double r;    // Радиус (расстояние от начала координат до точки)
//     double theta;    // Угол (в радианах)
// };

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

bool NewPoint(std::string s, std::vector<decartpoint> &points) {
}

int main() {
    int n, m;
    std::cin >> n;
    while (n--) {
        std::cin >> m;
        std::vector<decartpoint> points(m);
        for (int i = 0; i < m; i++) {
            std::string s;
            std::cin >> s;
            NewPoint(s, points);
        }
    }
    // Polar_Point p;    // Пример полярных координат: r = 5, theta = 1.2 радиана
    // p.r = 2.0;
    // p.theta = degreesToRadians(45);
    // DeCart_Point cartesian = polarToDeCart(p);
    // std::cout << "Декартовы координаты: x = " << cartesian.x << ", y = " << cartesian.y << std::endl;
    return 0;
}