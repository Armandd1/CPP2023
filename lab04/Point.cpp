//
// Created by arman on 2023. 10. 16.
//

#include <iostream>
#include <cmath>
#include "Point.h"

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "(" << x << "," << y << ")" << endl;
}

double Point::distanceTo(const Point& point)const {
    return  sqrt(pow(this->x - point.x,2)+pow(this->y-point.y, 2));
}



