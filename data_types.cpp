//
// Created by Thund on 19.02.2024.
//


#include "data_types.h"

fig::Point::Point() : x(0), y(0){}

fig::Point::Point(const double &_x, const double &_y) : x(_x), y(_y) {}

fig::Point::Point(const std::pair<double, double> &_x): x(_x.first), y(_x.second){}

fig::Triangle::Triangle() : square(0){}

fig::Triangle::Triangle(const std::pair<double, double> &_a, const std::pair<double, double> &_b, const std::pair<double, double> &_c) {
    a = _a;
    b = _b;
    c = _c;
    square = 0;
    calculate_square();
}

void fig::Triangle::calculate_square() {
    double _a = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    double _b = sqrt(pow((a.x - c.x), 2) + pow((a.y - c.y), 2));
    double _c = sqrt(pow((b.x - c.x), 2) + pow((b.y - c.y), 2));
    double _p = (_a + _b + _c) / 2;
    square = (_p * (_p - _a) * (_p - _b) * (_p - _c));
}

double fig::Triangle::get_square() {
    return square;
}

bool fig::Triangle::operator!=(const fig::Triangle &T) const {
    return square != T.square;
}

bool fig::Triangle::operator==(const fig::Triangle &T) const {
    return square == T.square;
}

bool fig::Triangle::operator>(const fig::Triangle &T) const {
    return square > T.square;
}

bool fig::Triangle::operator<(const fig::Triangle &T) const {
    return square < T.square;
}
