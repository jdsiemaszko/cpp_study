#include <iostream>
#include "pointers_lib.h"
#include <random>

int main() {
    std::random_device rd; // Seed the generator with a truly random value from the OS
    std::mt19937 gen(rd()); // Mersenne Twister 19937 is a popular pseudo-random number generator

    std::uniform_int_distribution<int> distribution(0, 10);

    std::cout << "wybierz stopnie wielomianow (2 liczby)" << std::endl;

    int stopien1, stopien2;
    std::cin >> stopien1;
    std::cin >> stopien2;
    

    int * w1 = new int[stopien1+1];
    int * w2 = new int[stopien2+1];

    for (int i; i < stopien1+1; i++) {
        *(w1+i) = distribution(gen);
    }
    for (int i; i < stopien2+1; i++) {
        *(w2+i) = distribution(gen);
    }

    std::cout<<"Wielomiany:" << std::endl;
    write(w1, stopien1+1);
    write(w2, stopien2+1);

    // suma:
    int * wsum = new int[std::max(stopien1+1, stopien2+1)];
    for (int j = 0; j < std::max(stopien1+1, stopien2+1); j++) {
        wsum[j] = 0;
        if (j < stopien1+1) {
            wsum[j] +=w1[j];
        }
        if (j < stopien2+1) {
            wsum[j] += w2[j];
        }
    }

    write(wsum, std::max(stopien1+1, stopien2+1));
    


    int * wmult = new int[stopien1 + stopien2+1]; 
    for (int k = 0; k < stopien1+stopien2+1; k++) { // clean up wmult
        wmult[k] = 0;
    }

    for (int i = 0; i < stopien1+1; i++) {
        for (int j = 0; j < stopien2+1; j++) {
            wmult[i+j] += w1[i] * w2[j];
        }
    }

    write(wmult, stopien1+stopien2+1);

    delete []w1,
    delete []w2; 
    delete []wsum; 
    delete []wmult;
    return 0;
}

