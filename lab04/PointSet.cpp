//
// Created by arman on 2023. 10. 16.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "PointSet.h"

PointSet::PointSet(int n) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 50); // return a number in the given range
    this->n=n;
    for (int i = 0; i < n; ++i) {
        int x = dist(mt);
        int y = dist(mt);
        Point newPoint(x, y);



        points.push_back(newPoint);
    }
    computeDistances();
}

void PointSet::computeDistances() {
    double dist;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; j++){
            dist = points[i].distanceTo(points[j]);
            distances.push_back(dist);
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(),distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(),distances.end());
}

int PointSet::numDistances() const{
    return distances.size();
}

void PointSet::printPoints() const {
    for (int i = 0; i < points.size(); ++i) {
        points[i].print();
    }
}

void PointSet::printDistances() const {
    for (int i = 0; i < distances.size(); ++i) {
        cout<<distances[i]<<" ";
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(),points.end(),[](const Point&a,const Point&b)->bool {
        return a.getX()<b.getX();});
}

void PointSet::sortPointsY() {
    sort(points.begin(),points.end(),[](const Point&a,const Point&b)->bool {
        return a.getY()<b.getY();});
}

void PointSet::sortDistances() {
    sort(distances.begin(),distances.end());
}

int PointSet::numDistinctDistances() {
    vector<double>  newVector = distances;
    auto last = unique(newVector.begin(),newVector.end());
    return last - newVector.begin();
}


