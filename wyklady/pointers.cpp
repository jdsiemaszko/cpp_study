#include <iostream>
#include <cmath>
using namespace std;

int g = 3;

int main() {

    // int value = 10;

    // int* pointer = &value;
    // cout << sizeof(value) << endl;
    // for (int i=0; i<5; i++) {
    //     cout << pointer + i << "\n";
    // }

    // double table[3] = {1000, 20, 3};
    // // cout << table[0+2] << endl;
    
    // // cout << 2[table] << endl;
    // // cout << table[2] << endl;
    // cout << *table + 2 << endl;
    // cout << *(table+2) << endl;
    // cout << *(table)+2 << endl;

    // const int i = 8;
    // int* arr = new int[i];
    // for (int j = 0; j < i; j++) {
    //     *(arr + j) = j;
    //     cout << *(arr+j) << endl;
    // }
  
    // delete []arr;
    cout << "g is equal to " << g << endl;
    int g = 5;
    cout << "g is equal to " << g << endl;
    cout << "global g is equal to " << ::g << endl;
    for (int i=0; i<3; i++) {
        g = 7;
        cout << "g is equal to " << g << endl;
        cout << "global g is equal to " << ::g << endl;
    }
    cout << "g is equal to " << g << endl;
    cout << "global g is equal to " << ::g << endl;


return 0;}