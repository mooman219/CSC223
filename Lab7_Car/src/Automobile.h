#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

class Automobile {
public:
    /*
     * Creates the automobile class with the default values
     */
    Automobile();

    /*
     * Function: setId()
     *
     * Param: id - The ID to set the automobile to.
     * Postcondition: The ID of the car matches the given ID.
     */
    void setId(int argId);

    /*
     * Function: setMake()
     *
     * Param: make - The make to set the automobile to.
     * Postcondition: The make of the car matches the given make.
     */
    void setMake(string make);

    /*
     * Function: setModel()
     *
     * Param: model - The model to set the automobile to.
     * Postcondition: The model of the car matches the given model.
     */
    void setModel(string model);

    /*
     * Function: setMileage()
     *
     * Param: mileage - The mileage to set the automobile to.
     * Postcondition: The mileage of the car matches the given mileage.
     */
    void setMileage(int argMileage);

    /*
     * Function: setCost()
     *
     * Param: cost - The cost to set the automobile to.
     * Postcondition: The cost of the car matches the given cost.
     */
    void setCost(float argCost);

    /*
     * Function: getId()
     *
     * Return: The id of the automobile.
     */
    int getId();

    /*
     * Function: getMake()
     *
     * Return: The make of the automobile.
     */
    string getMake();

    /*
     * Function: getModel()
     *
     * Return: The model of the automobile.
     */
    string getModel();

    /*
     * Function: getMileage()
     *
     * Return: The mileage of the automobile.
     */
    int getMileage();

    /*
     * Function: getCost()
     *
     * Return: The cost of the automobile.
     */
    float getCost();

    /*
     * Function: operator<<()
     *
     * Postcondition: This will print out the car's
     *      information to the given stream.
     * Return: The cost of the automobile.
     */
    friend ostream& operator<<(ostream& out, Automobile automobile);
private:
    int id;
    string make;
    string model;
    int mileage;
    float cost;
};

#endif
