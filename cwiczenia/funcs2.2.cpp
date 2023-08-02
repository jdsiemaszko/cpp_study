#include <iostream>
#include <cstdarg>

void filter(int * t, int n, bool (*f)(int)) {
    /*
    t - tablica (pointer)
    n - ilosc elementow t
    *f - pointer do funkcji bool f(int) (dowolna)
    */
   for (int i=0;i<n;i++) {
    if (f(*(t+i))) {
        std::cout << *(t+i) << std::endl;
    }
   }

}

bool geq0(int x) {
    return x>=0;
}



int main() {

    int t[] = {1, -1, 0, 0, -3};
    int N = sizeof(t) / sizeof(int);
    filter(t, N, geq0);
    return 0;
}