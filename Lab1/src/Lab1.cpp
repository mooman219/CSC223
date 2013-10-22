//============================================================================
// Name        : Lab1.cpp
// Author      : Joe Cumbo
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

void pause() {
    std::cout << std::endl << "Press any key to continue...";
    getchar();
}

int main() {
    char symbol1, symbol2;
    cout << "Enter two initals, without any period:\n";
    cin >> symbol1 >> symbol2;
    cout << "The two initals are: "
            << symbol1 << " "
            << symbol2 << "\n"
            << "The end.";
    pause();
    return 0;
}
