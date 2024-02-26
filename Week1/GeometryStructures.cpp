#include <iostream>
#include <cmath>

struct Point{
    int x;
    int y;
};

void inputPoint(Point& point){
    std::cin >> point.x;
    std::cin >>point.y;
}

int getQuadrant(const Point& p){
    if(p.x > 0, p.y >0)
        return 1;
    else if(p.x < 0, p.y>0)
        return 2;
    else if(p.x < 0, p.y< 0)
        return 3;
    else if(p.x>0, p.y < 0)
        return 4;
    else
        return 0;
}

double distancePoints(const Point& point1,const Point& point2){
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;

    return std::sqrt((dx * dx) + (dy * dy));
}

struct Circle{
    double r;
    Point center;
};

bool isLieCounter(const Point& point,const Circle& circle){
    return distancePoints(point, circle.center) == circle.r;
}

bool isCrosses(const Circle& circle1, const Circle& circle2){
    double centerDist = distancePoints(circle1.center, circle2.center);
    double sumOfR = circle1.r + circle2.r;

    if(centerDist < sumOfR)
        return false;
    else
        return true;
}

bool isInCircle(const Circle& circle1, const Circle& circle2){
    if(circle1.r > circle2.r)
        return circle1.r - circle2.r >0;
    else
        return circle2.r - circle1.r >=0;
}

struct Vector{
    int points[100];
    unsigned int n;
};

double scalarProduct(const Vector& vector){
    double result;

    for(size_t i = 0; i < vector.n; i++){
        result += vector.points[i] * vector.points[i];
    }

    return result;
}


int main() {

    return 0;
}
