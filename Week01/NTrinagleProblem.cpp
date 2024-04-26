#include <iostream>
#include <cmath>

struct Point{
    int x;
    int y;
};

struct Triangle{
    Point point1;
    Point point2;
    Point point3;
};


void readPoint(Point& point){
    std::cin >> point.x >> point.y;
}

void readTriangle(Triangle& triangle){
    readPoint(triangle.point1);
    readPoint(triangle.point2);
    readPoint(triangle.point3);
}

double distancePoints(const Point& point1,const Point& point2){
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;

    return std::sqrt((dx * dx) + (dy * dy));
}

double perimeterOfTriangle(const Triangle& triangle){
    double a = distancePoints(triangle.point1, triangle.point2);
    double b = distancePoints(triangle.point2, triangle.point3);
    double c = distancePoints(triangle.point1, triangle.point3);

    return a + b + c;
}

double areaOfTriangle(const Triangle& triangle) {
    double halfPerimeter = perimeterOfTriangle(triangle) / 2;
    double a = distancePoints(triangle.point1, triangle.point2);
    double b = distancePoints(triangle.point2, triangle.point3);
    double c = distancePoints(triangle.point3, triangle.point1);

    return sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));}

void sortAreas(Triangle* triangles, size_t size){
    double* areasOfTriangles = new double [size];
    size_t minIndex;
    for(size_t i = 0; i < size; i++){
        areasOfTriangles[i] = areaOfTriangle(triangles[i]);
    }

    for(size_t i = 0; i < size; i++){
        minIndex = i;
        for(size_t j = i; j < size; j++){
            if(areasOfTriangles[i] < areasOfTriangles[j])
                minIndex = j;
        }
        if(minIndex != i){
            std::swap(areasOfTriangles[i], areasOfTriangles[minIndex]);
            std::swap(triangles[i], triangles[minIndex]);
        }
    }

    delete[] areasOfTriangles;
}

void printAreasOfTriangles(const Triangle* triangles, size_t size){
    double* areasOfTriangles = new double [size];
    for(size_t i = 0; i < size; i++) {
        areasOfTriangles[i] = areaOfTriangle(triangles[i]);
    }

    for(size_t i = 0; i< size; i++){
        std::cout << areasOfTriangles[i] << '\n';
    }

    delete[] areasOfTriangles;
}

int main() {
    unsigned int numOfTriangles;
    std::cin >> numOfTriangles;

    Triangle* triangles = new Triangle[numOfTriangles];

    for(int i = 0; i < numOfTriangles; i++){
        readTriangle(triangles[i]);
    }

    sortAreas(triangles, numOfTriangles);
    printAreasOfTriangles(triangles, numOfTriangles);

    delete[] triangles;
    return 0;
}
