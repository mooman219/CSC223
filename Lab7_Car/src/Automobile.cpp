#include "Automobile.h"

Automobile::Automobile() {
    this->cost = 0;
    this->id = 0;
    this->mileage = 0;
    this->make = "";
    this->model = "";
}

void Automobile::setId(int argId) {
    id = argId;
}

ostream& operator<<(ostream& out, Automobile automobile) {
    out << "(" << automobile.getId() << ", " << automobile.getModel() << ", " << automobile.getMileage() << ", " << automobile.getCost() << ")";
    return out;
}

void Automobile::setMake(string make) {
    this->make = make;
}

void Automobile::setModel(string model) {
    this->model = model;
}

void Automobile::setMileage(int mileage) {
    this->mileage = mileage;
}

void Automobile::setCost(float cost) {
    this->cost = cost;
}

int Automobile::getId() {
    return id;
}

string Automobile::getMake() {
    return make;
}

string Automobile::getModel() {
    return model;
}

int Automobile::getMileage() {
    return mileage;
}

float Automobile::getCost() {
    return cost;
}
