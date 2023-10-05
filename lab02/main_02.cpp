#include "Point.h"

int main(int argc, char **argv) {
    Point p1(2, 3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
    Point p2(100, 200);
    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;
    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);
    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;
//    p1.print();

    cout << distance(p1, p2);

    if (isSquare(p1, p2, *pp1, *pp2)) {
        cout << "\nsquare" << endl;
    } else {
        cout << "\nnot square" << endl;
    }

    testIsSquare("points.txt");

    delete pp1;
    delete pp2;
    int N;
    cout << "Adja meg a pontok szamat (N): ";
    cin >> N;

    Point *points = createArray(N);
//    for (int i = 0; i < N; ++i) {
//        cout << "Pont " << i + 1 << ": (" << points[i].getX() << ", " << points[i].getY() << ")" << endl;
//    }

//    printArray(points, N);

    pair<Point, Point> closestPair = closestPoints(points, N);

    cout << "Legkozelebbi pontpar:\n ";
    closestPair.first.print();
    closestPair.second.print();

    pair<Point, Point> farthestPair = farthestPoints(points, N);

    cout << "Legtvolabbi pontpar:\n ";
    farthestPair.first.print();
    farthestPair.second.print();

    sortPoints(points, N);

    cout << "Legtavolabb pontok az origotol:\n ";
    Point* farthest = farthestPointsFromOrigin(points, N);
    for (int i = 0; i < 10; ++i) {
        farthest[i].print();
    }

    deletePoints(points);
    deletePoints(farthest);

    return 0;
}
