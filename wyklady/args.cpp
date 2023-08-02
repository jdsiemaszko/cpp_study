#include <iostream>

int main(int args_num, char * argv[]) {
    for (int i = 1; i< args_num; i++) {
        std::cout << argv[i] << std::endl; 
    }
    return 0;
}