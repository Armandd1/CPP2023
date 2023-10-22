    //
// Created by arman on 2023. 10. 16.
//

#ifndef LAB4_POINT_H
#define LAB4_POINT_H
#define M 2000

    using namespace std;

    class Point {
    private:
        int x, y;
    public:
        Point(int x = 0, int y = 0);

        int getX() const;

        int getY() const;

        void print() const;

        double distanceTo(const Point& point)const ;
    };


#endif //LAB4_POINT_H
