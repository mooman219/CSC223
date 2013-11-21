#include <istream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Problem 5, part C
    cout << "Problem 5, part C:" << endl;
    int length;
    cout << "Length: ";
    cin >> length;
    int y[length];
    cout << "Size: " << sizeof(y) / sizeof(*y)  << endl;
    // Input: "5"
    // Output: "5"

    /**
     * Why you need "sizeof(y) / sizeof(*y)"
     *
     * sizeof(y) will return the total byte size of the array.
     * sizeof(*y) will return the byte size of the element type.
     *
     * In the Problem 5, part C example, if you enter and input
     * of 5, then an array of 5 ints is created.
     *
     * sizeof(*y) will return 4. Each int requires 4 bytes.
     * sizeof(y) will return 20. The total size of the array is 20 bytes
     *
     * "sizeof(y) / sizeof(*y)" really means "TotalSize / ElementSize", which
     * will give you the number of elements in the array.
     */



    // Problem 5, part D
    cout << endl << "Problem 5, part D:" << endl;
    const int size = 4;
    int x[size - 4];
    cout << "Size: " << sizeof(x) / sizeof(*x) << endl;
    // Output: "Size: 0"
    return 0;
}
