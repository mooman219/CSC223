#include "TestClass.h"
#include <iostream>

using namespace std;

string message = "Var test.";

TestClass::TestClass() {
    cout << "Created." << endl;
}

void TestClass::printTest(){
    cout << message << endl;
}

