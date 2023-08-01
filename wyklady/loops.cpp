#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // double i = 1.0;
    // while (i > 1e-7) {
    //     cout << i << "\n";
    //     i /=2;
    // }

    // for (double i = 1.0; i > 1e-9; i/=2) {
    //     cout << i << "\n";
    // }
    int N = 10;
    int list[N];
    for (int i = 0; i < N; i++) {
        list[i] = pow(i, i);
    }
    for (int j : list) {
        cout << j << "\n";
    }

    return 0;
}