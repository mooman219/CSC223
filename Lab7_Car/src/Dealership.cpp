#include "Dealership.h"
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

// constructor to set the number of  cars to zero
Dealership::Dealership() {
    numCars = 0;
}

// constructor to set the number of cars
Dealership::Dealership(int nCar) {
    numCars = nCar;
}

// *********************************************************************************
//FUNCTION: addCar()
//
//PRECONDITION: The car must have appropriate data in it
//POSTCONDITION: a function to add an automobile to the list
// If the array is full, return false, else add the car to the list and return true
// If the car is already in the list, then replace it with aCar
// *********************************************************************************
bool Dealership::addCar(Automobile aCar) {
    bool add = false;
    if(numCars < CAPACITY) {
        carList[numCars] = aCar;
        numCars++;
        add = true;
    } else {
        add = false;
    }
    return add;
}

// *********************************************************************************
//FUNCTION: deleteCar()
//
//PRECONDITION: Car must have appropriate data in it
//POSTCONDITION: a function to delete an automobile from the list
// if the array is empty, or the car is not in the array return false,
// else remove the car from the list and return true
// *********************************************************************************
bool Dealership::deleteCar(Automobile aCar) {
    bool found = false;
    int carList_Id;
    int aCar_Id;
    if(numCars == 0) {
        found = false;
    } else {
        for(int i = 0; i < numCars; i++) {
            carList_Id = carList[i].getId();
            aCar_Id = aCar.getId();
            if(carList_Id == aCar_Id) {
                found = true;
                for(int j = i; j <= numCars; j++) {
                    carList[j] = carList[j + 1];
                }
                i--;
                numCars--;
            }
        }
    }
    return found;
}

// *********************************************************************************
//FUNCTION: retrieveCar()
//
//PRECONDITION: The input parameter aCar may hold only part or all of the information about
// the automobile, but must have the automobile id number( to be able to
// compare it  with a car in the list)
//POSTCONDITION: a function that returns an Automobile from the list
// The function returns true if aCar was in the list, else it returns false
// *********************************************************************************
bool Dealership::retrieveCar(Automobile& aCar) {
    int carList_Id = 0;
    int aCar_Id = 0;
    bool found = false;
    if(numCars == 0) {
        found = false;
    } else {
        for(int i = 0; i < numCars; i++) {
            carList_Id = carList[i].getId();
            aCar_Id = aCar.getId();
            if(carList_Id == aCar_Id) {
                found = true;
                aCar = carList[i];
            }
        }
    }
    return found;
}

// *********************************************************************************
//FUNCTION: totalInvestment()
//
//PRECONDITION: Cars must have appropriate data in them and carry
// a cost
//POSTCONDITION: a function that returns the total cost that
// the dealership invested in cars
// *********************************************************************************
double Dealership::totalInvestment() {
    double totalCost = 0;
    for(int i = 0; i < numCars; i++) {
        totalCost += carList[i].getCost();
    }
    return totalCost;
}

// *********************************************************************************
//FUNCTION: operator<<()
//
//PRECONDITION: Cars must have appropriate data in them
//POSTCONDITION: overload the << operator a function to print
// all the cars in the Dealership in ascending order by
// cost of  the car*(calls the sort function).
// For each car print the Car ID number,
// car model,  Car make, mileage, owner car cost.
// *********************************************************************************
ostream& operator<<(ostream& out, Dealership dealer) {
    dealer.sort();
    int numOfCars = 0;
    for(int i = 0; i < CAPACITY; i++) {
        if(dealer.carList[i].getModel() != "") {
            numOfCars++;
        }
    }

    out << "------------------------------------------------------------------------------" << endl;
    out << left << setw(12) << "ID Number" << setw(18) << "Make" << setw(12) << "Model" << setw(12) << "Mileage" << setw(12) << "Cost" << endl;
    out << "------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < numOfCars; i++) {
        out << left << setw(12) << dealer.carList[i].getId() << setw(18) << dealer.carList[i].getMake() << setw(12) << dealer.carList[i].getModel() << setw(12) << dealer.carList[i].getMileage() << setw(12) << dealer.carList[i].getCost() << endl;
    }
    return out;
}

// *********************************************************************************
//FUNCTION: sort()
//
//PRECONDITION: There must be cars in the list with a cost appended to
// them
//POSTCONDITION: a function that sorts the List of cars in ascending
// order by Cost
// *********************************************************************************
void Dealership::sort() {
    double min = 0;
    int minIndex = 0;
    int length = numCars;
    Automobile tmp[CAPACITY];
    if(numCars != 0) {
        for(int j = 0; j < numCars; j++) {
            min = carList[length - 1].getCost();
            for(int i = 0; i < length; i++) {
                if(carList[i].getCost() <= min) {
                    min = carList[i].getCost();
                    minIndex = i;
                }
            }
            length--;
            tmp[j] = carList[minIndex];
            for(int k = minIndex; k < CAPACITY - 1; k++) {
                carList[k] = carList[k + 1];
            }
            minIndex = 0;
        }
        for(int l = 0; l < numCars; l++) {
            carList[l] = tmp[l];
        }
    }
}
