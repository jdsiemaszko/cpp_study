#include <iostream>
#include "pointers_lib.h"
#include <random>
#include <cmath>

long long factorial(long long n) {
    if (n==0) {
        return 1;
    }
    return n * factorial(n-1);
}


long long binomial(long long n, long long k) {
    static int count = 0;
    count++;
    std::cout << "Current count: " << count << std::endl;

    if (k < 0 || k > n) {
        return 0;
    }
    if (n <= 1) {
        return 1;
    }
    return binomial(n-1, k-1) + binomial(n-1, k);
}

short int no_of_sols(double a, double b, double c, double &x1, double &x2) {
    /*
    a, b, c - coefficients of a quadratic equation
    x1, x2 - containers for solutions (if any)
    */

   double delta_squared = b*b - 4*a*c;
   if (delta_squared > 0) {
    x1 = (sqrt(delta_squared) - b) / 2 / a;
    x2 = (-b - sqrt(delta_squared)) / 2 / a;
    return 2;
   }
   else if (delta_squared == 0) {
    x1 = (-1) * b / 2 / a;
    x2 = (-1) * b / 2 / a;
    return 1;
   }
   else {
    return 0;
   }

}

int main() {
    // std::cout << binomial(17,  13)<<std::endl;

    double a = 1.0;
    double b = 69.0;
    double c = 3.0;
    double x1, x2;

    short int N = no_of_sols(a, b, c, x1, x2);

    std::cout << "No. of solutions: " << N << std::endl;
    std::cout << " Sols: " << x1 << " " << x2 << std::endl;


return 0;}