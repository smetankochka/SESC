#include <iostream>
#include <cmath>

struct Polar_Point {
    double r;    // Радиус (расстояние от начала координат до точки)
    double theta;    // Угол (в радианах)
};

struct DeCart_Point {
    double x;    // Координата x
    double y;    // Координата y
};

double degreesToRadians(double degrees) {
    const double pi = 3.14159265358979323846;
    return degrees * (pi / 180.0);
}

DeCart_Point polarToDeCart(const Polar_Point& p) {
    DeCart_Point c;
    c.x = p.r * cos(p.theta);
    c.y = p.r * sin(p.theta);
    return c;
}

int main() {
    Polar_Point p;    // Пример полярных координат: r = 5, theta = 1.2 радиана
    p.r = 2.0;
    p.theta = degreesToRadians(45);
    DeCart_Point cartesian = polarToDeCart(p);
    std::cout << "Декартовы координаты: x = " << cartesian.x << ", y = " << cartesian.y << std::endl;
    return 0;
}