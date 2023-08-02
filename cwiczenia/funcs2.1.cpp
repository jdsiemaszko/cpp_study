#include <iostream>
#include <cstdarg>


int sumation(int N, ...) {
    va_list ap;
    va_start(ap, N);
    
    int sum = 0;
    for (int i = 0; i<N; i++) {
        sum += va_arg(ap, int);
    }

    return sum;

}

double mean(int N, ...) {
    va_list ap;
    va_start(ap, N);
    
    int sum = 0;
    for (int i = 0; i<N; i++) {
        sum += va_arg(ap, int);
    }

    return (double) sum / N;
}


int main() {

    std::cout<<sumation(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)<<std::endl;
    std::cout<<mean(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)<<std::endl;

    // std::cout<<sumation(2, 3, 5)<<std::endl;
    // std::cout<<sumation(8, 1, 1, 1, 1, 1, 1, 1, 1)<<std::endl;


    return 0;
}