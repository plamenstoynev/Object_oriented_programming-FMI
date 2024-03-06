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

double distancePoints(const Point& point1,const Point& point2){
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;

    return std::sqrt((dx * dx) + (dy * dy));
}

struct Square{
    Point point1;
    Point point2;
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
    Square,
    Circle,
    Rectangle
};

union Shape{
    Square square;
    Circle circle;
    Rectangle rectangle;
};

double areaOfShape(const Shape& shape, const ShapeType& type){
    double area;
    double PI = 3.14;
    switch (type) {
        case ShapeType::Square:
            area = distancePoints(shape.square.point1, shape.square.point2) * distancePoints(shape.square.point1, shape.square.point2);
            break;
        case ShapeType::Rectangle:
            area = distancePoints(shape.rectangle.point1, shape.rectangle.point2) * distancePoints(shape.rectangle.point1, shape.rectangle.point2);
            break;
        case ShapeType::Circle:
            area = PI * shape.circle.r * shape.circle.r;
            break;
    }
    return area;
}

int main(){
    Shape shape;
    ShapeType type;
    std::cout << "Enter type of shape" << std::endl;
    std::cout << "1 for Square" << std::endl;
    std::cout << "2 for Circle" << std::endl;
    std::cout << "3 for Rectangle" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            type = ShapeType::Square;
            std::cout << "Enter first point" << std::endl;
            inputPoint(shape.square.point1);
            std::cout << "Enter second point" << std::endl;
            inputPoint(shape.square.point2);
            break;
        case 2:
            type = ShapeType::Circle;
            std::cout << "Enter center" << std::endl;
            inputPoint(shape.circle.center);
            std::cout << "Enter radius" << std::endl;
            std::cin >> shape.circle.r;
            break;
        case 3:
            type = ShapeType::Rectangle;
            std::cout << "Enter first point" << std::endl;
            inputPoint(shape.rectangle.point1);
            std::cout << "Enter second point" << std::endl;
            inputPoint(shape.rectangle.point2);
            break;
    }
    std::cout << "Area of shape is: " << areaOfShape(shape, type) << std::endl;
    return 0;

}