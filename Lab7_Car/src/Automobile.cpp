#include "Automobile.h"

/*
 * Creates the automobile class with the default values
 */
Automobile::Automobile() {
    this->cost = 0;
    this->id = 0;
    this->mileage = 0;
    this->make = "";
    this->model = "";
}

/*
 * Function: setId()
 *
 * Param: id - The ID to set the automobile to.
 * Postcondition: The ID of the car matches the given ID.
 */
void Automobile::setId(int id) {
    this->id = id;
}

/*
 * Function: setMake()
 *
 * Param: make - The make to set the automobile to.
 * Postcondition: The make of the car matches the given make.
 */
void Automobile::setMake(string make) {
    this->make = make;
}

/*
 * Function: setModel()
 *
 * Param: model - The model to set the automobile to.
 * Postcondition: The model of the car matches the given model.
 */
void Automobile::setModel(string model) {
    this->model = model;
}

/*
 * Function: setMileage()
 *
 * Param: mileage - The mileage to set the automobile to.
 * Postcondition: The mileage of the car matches the given mileage.
 */
void Automobile::setMileage(int mileage) {
    this->mileage = mileage;
}

/*
 * Function: setCost()
 *
 * Param: cost - The cost to set the automobile to.
 * Postcondition: The cost of the car matches the given cost.
 */
void Automobile::setCost(float cost) {
    this->cost = cost;
}

/*
 * Function: getId()
 *
 * Return: The id of the automobile.
 */
int Automobile::getId() {
    return id;
}

/*
 * Function: getMake()
 *
 * Return: The make of the automobile.
 */
string Automobile::getMake() {
    return make;
}

/*
 * Function: getModel()
 *
 * Return: The model of the automobile.
 */
string Automobile::getModel() {
    return model;
}

/*
 * Function: getMileage()
 *
 * Return: The mileage of the automobile.
 */
int Automobile::getMileage() {
    return mileage;
}

/*
 * Function: getCost()
 *
 * Return: The cost of the automobile.
 */
float Automobile::getCost() {
    return cost;
}

/*
 * Function: operator<<()
 *
 * Return: The cost of the automobile.
 */
ostream& operator<<(ostream& out, Automobile automobile) {
    out << "(" << automobile.getId() << ", " << automobile.getModel() << ", " << automobile.getMileage() << ", " << automobile.getCost() << ")";
    return out;
}

