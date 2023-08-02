#include <iostream>
#include <cstdarg>
#include <random>
#include "pointers_lib.h"

void sort(int * t, int n, bool (*f)(int, int), bool up = true) {
    /*
    t - tablica
    n - t.size()
    f - funkcja porównująca
    up - sort rosnący czy malejący
    
    */

    for (int i=0;i<n;i++) {
        for (int j=i+1; j<n;j++) {
            if (up) {
                if (f(t[i], t[j])) {
                    int dummy = t[i];
                    t[i] = t[j];
                    t[j] = dummy;
                    }
                }
            else {
                if (!f(t[i], t[j])) {
                    int dummy = t[i];
                    t[i] = t[j];
                    t[j] = dummy;
                    }

            }
            // std::cout<<"Current state of array:"<<std::endl;
            // write(t, n);
        }
    }
}

void sort(int t[][2], int n, bool (*f)(int*, int*), bool up = true) {
    /*
    t - tablica
    n - t.size()
    f - funkcja porównująca
    up - sort rosnący czy malejący
    
    */

    for (int i=0;i<n;i++) {
        for (int j=i+1; j<n;j++) {
            if (up) {
                if (f(t[i], t[j])) {
                    int dummy1 = t[i][0];
                    int dummy2 = t[i][1];
                    t[i][0] = t[j][0];
                    t[i][1] = t[j][1];

                    t[j][0] = dummy1;
                    t[j][1] = dummy2;
                    }
                }
            else {
                if (!f(t[i], t[j])) {
                    int dummy1 = t[i][0];
                    int dummy2 = t[i][1];
                    t[i][0] = t[j][0];
                    t[i][1] = t[j][1];

                    t[j][0] = dummy1;
                    t[j][1] = dummy2;
                    }

            }
            // std::cout<<"Current state of array:"<<std::endl;
            // write(t, n);
        }
    }
}

bool f(int a, int b) {
    return a>=b; 
}


bool p1(int a[2], int b[2]) {
    return pow(2, a[0]) * pow(3, a[1]) >= pow (2, b[0]) * pow(3, b[1]);
}

bool p2(int a[2], int b[2]) {
    if (a[0] > b[0]) {
        return true;
    }
    else if (a[0] == b[0] && a[1] > b[1]) {
        return true;
    }
    return false;
}

int main() {
    std::random_device rd; // Seed the generator with a truly random value from the OS
    std::mt19937 gen(rd()); // Mersenne Twister 19937 is a popular pseudo-random number generator

    std::uniform_int_distribution<int> distribution(0, 100);

    int N = 100;
    // int tab[N];
    // for (int i=0;i<N;i++) {
    //     tab[i] = distribution(gen);
    // }

    int tab[N][2];
    for (int i=0;i<N;i++) {
        tab[i][0] = distribution(gen);
        tab[i][1] = distribution(gen);
    }

    // std::cout<<tab<<std::endl;
    write(tab, N);
    sort(tab, N, p2);
    write(tab, N);
    // std::cout<<tab<<std::endl;

    

    return 0;
}