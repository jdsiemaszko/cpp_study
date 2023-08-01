#include <iostream>
#include "pointers_lib.h"
#include <random>


double evaluate_poly(double arr[], int N, double x) {
    double value = 0.0;
    for (int i = 0; i<N+1; i++) {
        value += arr[i] * pow(x, i);
    }
    return value;
}

double integral_poly(double arr[], int N, double a, double b) {
    double aloc = std::min(a, b);
    double bloc = std::max(a, b);

    double integral_coeffs[N+2];
    integral_coeffs[0] = 0;
    for (int i = 0; i < N+1; i++) {
        integral_coeffs[i+1] = arr[i] / (i+1);
    }

    double value = evaluate_poly(integral_coeffs, N+1, bloc) - evaluate_poly(integral_coeffs, N+1, aloc);
    return value;
}

int random_number(int a, int b) {
    std::random_device rd; // Seed the generator with a truly random value from the OS
    std::mt19937 gen(rd()); // Mersenne Twister 19937 is a popular pseudo-random number generator

    std::uniform_int_distribution<int> distribution(a, b);

    int value = distribution(gen);
    return value;}

double random_number(double a, double b) {
    std::random_device rd; // Seed the generator with a truly random value from the OS
    std::uniform_real_distribution<double> unif(a, b); // Mersenne Twister 19937 is a popular pseudo-random number generator


    double value = unif(rd);
    return value;}


int main() {
    int N = 4;
    double poly[N+1] = {1.0, 5.0, 6.0, 1.0, 5.0};
    double x = 0.3758;

    double eval = evaluate_poly(poly, N, x);
    std::cout<<"Value of evaluation: " << eval << std::endl;

    double a = 1.0;
    double b = 1.1;
    double integral = integral_poly(poly, N, a, b);
    std::cout << "Value of integral between " << a << " and " << b << ": " << integral << std::endl;

    std::cout<<(int) random_number(3, 5) << std::endl;
    std::cout<<(double) random_number(3.5, 3.6) << std::endl;
return 0;}