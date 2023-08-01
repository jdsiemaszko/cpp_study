#include <iostream>
#include <cmath>
using namespace std;


const double pi = 3.14159265359;
const int N = 1000;

inline double area_of_a_circle(double radius) {
    return pi * radius * radius;
} 

int main() {

    double p[N];
    for (int i = 0; i < N; i++) {
        p[i] = (double) i;  // type change
    }
    for (double r : p) {
        cout << area_of_a_circle(r) << endl;
    }

    return 0;}