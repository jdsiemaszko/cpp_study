#include <iostream>

void write(int array[], int N) { // passing the address of the first element
    for (int i = 0; i < N; i++) {
        std::cout << *(array+i) << " ";
    }
    std::cout << "\n";
    return;
}

int sum_array(int array[], int N) {
    int s = 0;

    for (int i = 0; i < N; i++) {
        s += *(array+i);
    }
    std::cout << "Sum: " << s << std::endl;
    return s;
}

int max_array(int array[], int N) {
    int m = 0;

    for (int i = 0; i < N; i++) {
        if (*(array+i) > m) {
            m = *(array+i);
        }
    }
    std::cout << "Max: " << m << std::endl;
    return m;
}