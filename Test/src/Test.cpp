#include "TestClass.h"
#include <iostream>
#include <string>

using namespace std;

class Parent {
public:
    void m1() {
       cout << "p.m1" << endl;
    };
};

class Child: public Parent {
public:
    void m1() {
        cout << "c.m1" << endl;
    }
};

int main() {
    Parent p;
    Child c;

    p.m1();
    c.m1();

    Parent *pp = &p;
    Child *cc = &c;

    pp->m1();
    cc->m1();

    pp = &c;

    pp->m1();
    return 0;
}
