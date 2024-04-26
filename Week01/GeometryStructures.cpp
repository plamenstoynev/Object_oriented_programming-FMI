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

void inputCirlce(Circle& cirlce){
    inputPoint(cirlce.center);
    std::cin >> cirlce.r;
}

bool isLieCounter(const Point& point,const Circle& circle){
    return distancePoints(point, circle.center) == circle.r;
}

bool isCrosses(const Circle& circle1, const Circle& circle2){
    double centerDist = distancePoints(circle1.center, circle2.center);
    double sumOfR = circle1.r + circle2.r;

    if(centerDist < sumOfR)
        return true;
    else
        return false;
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

void inputVector(Vector& vector){
    std::cin >> vector.n;
    for(size_t i = 0; i < vector.n; i++){
        std::cin >> vector.points[i];
    }
}

double scalarProduct(const Vector& vector){
    double result;

    for(size_t i = 0; i < vector.n; i++){
        result += vector.points[i] * vector.points[i];
    }

    return result;
}


struct Line{
    int n;
};

void inputLine(Line& line){
    std::cin >> line.n;
}

void sortLines(Line* lines, size_t size){
    size_t minIndex;
    for(size_t i = 0; i < size; i++){
        minIndex = i;
        for(size_t j = 0; j < size; j++) {
            if (lines[i].n > lines[j].n)
                minIndex = j;
        }
        if(minIndex != i)
            std::swap(lines[i], lines[minIndex]);
    }
}


int main() {
    Point point1;
    Point point2;
    std::cout << "Input x and y for the point1 and point 2" << std::endl;
    inputPoint(point1);
    inputPoint(point2);
    std::cout << "The point1 is in " << getQuadrant(point1) << " quadrant" << std::endl;



    Circle cirlce1;
    Circle circle2;
    std::cout << "Input the center and radius for a circle1 and circle 2" << std::endl;
    inputCirlce(cirlce1);
    inputCirlce(circle2);




    std::cout << std::boolalpha << isLieCounter(point1, cirlce1) << std::endl;
    std::cout << std::boolalpha<< isCrosses(cirlce1, circle2) << std::endl;
    std::cout << std::boolalpha << isInCircle(cirlce1, circle2) << std::endl;



    Vector vector;
    inputVector(vector);
    std::cout << "Dot product: " << scalarProduct(vector);


    size_t size;
    std::cout << "Enter how many lines you want" << std::endl;
    std::cin >> size;
    Line* lines = new Line[size];
    for (size_t i = 0; i < size; ++i)
        inputLine(lines[i]);

    sortLines(lines, size);

    for (size_t i = 0; i < size; ++i)
        std::cout << lines[i].n << std::endl;


    delete[]lines;
    return 0;
}
