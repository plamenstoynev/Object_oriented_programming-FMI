#include <iostream>

struct Point{
    int x;
    int y;
};

void inputPoint(Point& point){
    std::cin >> point.x;
    std::cin >>point.y;
}


struct Triangle{
    Point point1;
    Point point2;
    Point point3;
};

struct Circle{
    double r;
    Point center;
};

struct Rectangle{
    Point point1;
    Point point2;
};

enum class ShapeType{
    Triangle,
    Circle,
    Rectangle
};

union Shape{
    Triangle triangle;
    Circle circle;
    Rectangle rectangle;
};

int main(){

}