#ifndef DEALERSHIP_H
#define DEALERSHIP_H

#include "Automobile.h"
#include <iostream>
using namespace std;

const int CAPACITY = 30;

class Dealership {
public:
    Dealership();
    // constructor to set the number of  cars to zero

    Dealership(int size);
    // constructor to set the number of  cars to zero

    bool addCar(Automobile aCar);
    // a function to add an automobile to the list
    //  If the array is full, return false, else add the car to the list and return true
    //  If the car is already in the list, then replace it with aCar

    bool deleteCar(Automobile aCar);
    // a function to delete an automobile from the list
    //  if the array is empty, or the car is not in the array return false, else remove  the
    // car from the list and return true

    bool retrieveCar(Automobile& aCar);
    // a function that returns an Automobile from the list
    //  The input parameter aCar may hold only part or all of the information about
    //  the automobile, but must have the automobile id number( to be able to
    //  compare it  with a car in the list)
    // The function returns true if aCar was in the list, else it returns false

    double totalInvestment();
    // a function that returns the total cost that the dealership invested in cars

    void printDealership();
    //print the dealership
    // For each car print the Car ID number, car model,  Car
    // mileage, owner car cost.

    friend ostream& operator<<(ostream& out, Dealership dealer);
    // overload the << operator a function to print all the cars in the Dealership in
    // ascending order by cost of  the car*.
    // For each car print the Car ID number, car model,  Car
    // mileage, owner car cost.

private:
    int numCars;
    // actual number of cars in the lot

    Automobile carList[CAPACITY];
    // array of cars

    void sort();
    //a method to sort the automobiles in the
    //dealership by cost of car
};

#endif
