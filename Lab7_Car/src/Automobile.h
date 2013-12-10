#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

class Automobile {
public:
    Automobile();
    void setId(int argId);
    void setMake(string make);
    void setModel(string model);
    void setMileage(int argMileage);
    void setCost(float argCost);
    int getId();
    string getMake();
    string getModel();
    int getMileage();
    float getCost();
    friend ostream& operator<<(ostream& out, Automobile automobile);
private:
    int id;
    string make;
    string model;
    int mileage;
    float cost;
};

#endif
