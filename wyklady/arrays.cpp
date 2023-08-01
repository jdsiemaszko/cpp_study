#include <iostream>
#include <cmath>
using namespace std;




int main() {

    int dim[3] = {3, 3, 3};
    int array[dim[0]][dim[1]][dim[2]];


    // fuckery
    for (int i=0; i < dim[0]; i++) {
        for (int j=0; j < dim[1]; j++) {
            for (int k=0; k < dim[2]; k++) {
                array[i][j][k] = i + j + k;
                cout << i + j + k;
                }
            
            
        cout << "\n";}
        
        
    cout << "\n";}


    return 0;
}