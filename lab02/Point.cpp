//
// Created by arman on 2023. 10. 02.
//
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
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

double distance(const Point &a, const Point &b) {
    double dx = b.getX() - a.getX();
    double dy = b.getY() - a.getY();
    return sqrt(dx * dx + dy * dy);
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double distances[6];

    distances[0] = distance(a, b);
    distances[1] = distance(a, c);
    distances[2] = distance(a, d);
    distances[3] = distance(b, c);
    distances[4] = distance(b, d);
    distances[5] = distance(c, d);

    sort(distances, distances + 6);

    return distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3] &&
           distances[4] == distances[5] && distances[0] != 0;

}

void testIsSquare(const char *filename) {
    ifstream myStream(filename);
    string line;
    while (getline(myStream, line)) {
        vector<string> words;
        istringstream iss(line);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        Point p1(stoi(words[0]), stoi(words[1]));
        p1.print();
        Point p2(stoi(words[2]), stoi(words[3]));
        p2.print();
        Point p3(stoi(words[4]), stoi(words[5]));
        p3.print();
        Point p4(stoi(words[6]), stoi(words[7]));
        p4.print();
        if (isSquare(p1, p2, p3, p4)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];
    srand(time(nullptr));
    for (int i = 0; i < numPoints; i++) {
        int x = rand() % 2000;
        int y = rand() % 2000;
        points[i] = Point(x, y);
    }

    return points;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        throw invalid_argument("Legalabb ket pont szukseges.");
    }

    double minDistance = numeric_limits<double>::max();
    pair<Point, Point> closestPair;

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return closestPair;
}

pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    if (numPoints < 2) {
        throw invalid_argument("Legalabb ket pont szukseges.");
    }

    double maxDistance = 0.0;
    pair<Point, Point> farthestPair;

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist > maxDistance) {
                maxDistance = dist;
                farthestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return farthestPair;
}

bool comparePoints(const Point& a, const Point& b) {
    return a.getX() < b.getX();
}

void sortPoints(Point* points, int numPoints) {
    sort(points, points + numPoints, comparePoints);
//    for (int i = 0; i < numPoints; ++i) {
//        points[i].print();
//    }
}

bool compareByDistance(const Point& a, const Point& b) {
    double distA = sqrt(a.getX() * a.getX() + a.getY() * a.getY());
    double distB = sqrt(b.getX() * b.getX() + b.getY() * b.getY());
    return distA > distB;
}

Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    if (numPoints <= 10) {
        Point* result = new Point[numPoints];
        copy(points, points + numPoints, result);
        return result;
    }

    sort(points, points + numPoints, compareByDistance);

    Point* result = new Point[10];
    copy(points, points + 10, result);

    return result;
}

void deletePoints(Point* points) {
    delete[] points;
}
