#include <iostream>
using namespace std;

int main() {
    
    double x;
    double y;
    char oper;
    cout << "Type a number \n \n";
    cin >> x;
    cout << "Type another number \n \n";
    cin >> y;
    cout << "Type the operation (+-*/) \n \n";
    cin >> oper;

    if (oper == '+') {
        cout << "The answer is: " << x + y << "\n";
    }
    else if (oper == '-') {
        cout << "The answer is: " << x - y << "\n";
    }
    else if (oper == '*') {
        cout << "The answer is: " << x * y << "\n";
    }
    else if (oper == '/') {
        cout << "The answer is: " << x / y << "\n";
    }
    else {
        cout << "Invalid operation! \n";
    }
    return 0;
}