#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Vector{ 
    public:
    double x;
    double y;
    Vector(double xc, double yc);
    void toString();
};

Vector::Vector(double xc, double yc) {
    x = xc;
    y = yc;
    return;
}
void Vector::toString() {
    std::cout << "(" << x << ',' << y << ')' << std::endl;
    return;
}

class Line{
    public:
    std::vector<Vector> points;

    void add(Vector vec);
    double len();
    bool is_closed();
    void shift(Vector vec);
    void rotate(double angle, Vector vec);
    void toString();
};

void Line::add(Vector vec) {
    points.push_back(vec);
    return;
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(
        (x1 - x2) * (x1 - x2)
        +
        (y1 - y2) * (y1 - y2)
    );
}

double Line::len() {
    double len = 0.0;
    for (int i=0;i<points.size()-1;i++) {
        len += dist(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
    }
    return len;

}
bool Line::is_closed() {
    return (points[0].x == points[points.size()-1].x && points[0].y == points[points.size()-1].y);
}

void Line::shift(Vector vec){
    for (int i=0;i<points.size();i++) {
        points[i].x += vec.x;
        points[i].y += vec.y;
    }
    return;
}

void Line::rotate(double angle, Vector vec) {
    // too lazy, sorry not sorry
    return;
}

void Line::toString() {
    for (Vector vec : points) {
        vec.toString();
    }
    std::cout<<std::endl;
    return;
}



int main() {
    std::random_device rd; // Seed the generator with a truly random value from the OS
    std::uniform_real_distribution<double> unif(-100, 100); // Mersenne Twister 19937 is a popular pseudo-random number generator

    int N = 10;

    Line line;
    for (int i =0;i<N;i++) {
        Vector new_vec(new_vec.x = unif(rd), new_vec.y = unif(rd));
        line.add(new_vec);
    }

    std::cout<<line.len()<<std::endl;
    line.toString();
    line.shift(Vector(1.0, 1.0));
    std::cout<<line.len()<<std::endl;
    line.toString();



return 0;}