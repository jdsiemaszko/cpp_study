#include <iostream>
#include "pointers_lib.h"

// void write(int array[], int N) { // passing the address of the first element
//     for (int i = 0; i < N; i++) {
//         std::cout << *(array+i) << " ";
//     }
//     std::cout << "\n";
//     return;
// }

// int sum(int array[], int N) {
//     int s = 0;

//     for (int i = 0; i < N; i++) {
//         s += *(array+i);
//     }
//     std::cout << "Sum: " << s << std::endl;
//     return s;
// }

// int max(int array[], int N) {
//     int m = 0;

//     for (int i = 0; i < N; i++) {
//         if (*(array+i) > m) {
//             m = *(array+i);
//         }
//     }
//     std::cout << "Max: " << m << std::endl;
//     return m;
// }

int main() {
    int arr[] = {1, 3, 0, 7, 9, 37, 0, 12, 2, 4};
    int N = sizeof(arr) / sizeof(int);

    int arr2[] = {1,3,5,7,9};
    int N2 = sizeof(arr2) / sizeof(int);

    int arr3[] = {2, 4, 6, 8};
    int N3 = sizeof(arr3) / sizeof(int);



    
    write(arr, N);
    sum(arr, N);
    max(arr, N);
    // int * inv_pointer = invert(arr, N);
    // write(inv_pointer, N);

    int array_pointer[N];
    for (int i = 0; i < N; i++) {
        *(array_pointer + i) = *(arr + N - i - 1);
    }
    write(array_pointer, N);

    int sum_array_pointer[N2 + N3];

    // counters for arrays 2 & 3
    int i = 0;
    int j = 0;
    int slot = 0;
    while (slot < N2+N3) { // if the first array is exhausted, load the second array
        if (i >= N2) {
            *(sum_array_pointer + slot) = *(arr3 + j); 
            j++;
        } 
        else if (j >= N3) { // if the second array is exhausted, load the first array (note that if BOTH are exhausted, the while loop stops)
            *(sum_array_pointer + slot) = *(arr2 + i);
            i++;
        }
        else if (*(arr2 + i) < *(arr3 + j)) { // check elementwise between the two arrays
            *(sum_array_pointer + slot) = *(arr2 + i);
            i++;
        }
        else {
            *(sum_array_pointer + slot) = *(arr3 + j);
            j++;
        }
        
        slot++;
    }
    write(arr2, N2);
    write(arr3, N3);
    write(sum_array_pointer, N2+N3);



     

return 0;}