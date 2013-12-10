#include "Dealership.h"
#include "Automobile.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

/*
 * Function: parseOption()
 *
 * Param: menuInput - The input line from the menu.
 * Return: The first integer in the menuInput.
 */
int parseOption(string &menuInput);

/*
 * Function: parseCar()
 *
 * Param: input - The input line to parse a car from.
 * Param: type - The method to use to parse the car.
 *      Valid options include:
 *          0, When reading from a file
 *          1, When reading all information for a car.
 *          2, When reading just the id for a car.
 * Return: The resulting car parsed from the input.
 */
Automobile parseCar(string &input, int type);

/*
 * Function: parseFile()
 *
 * Param: menuInput - The input line from the menu.
 * Param: dealer - The Dealership to add the processed
 *      cars to.
 */
void parseFile(string &menuInput, Dealership &dealer);

/*
 * Function: menuCall()
 *
 * Param: arg - The input line for the menu to read.
 * Param: dealer - The Dealership to being modified.
 * Param: out - The stream to write the output to.
 */
void menuCall(string arg, Dealership &dealer, ofstream &out);

/*
 * Function: main()
 *
 * This method is where the tests will take place.
 */
int main() {
    ofstream out;
    Dealership dealer = Dealership();

    out.open("out.txt");

    out << "Create the DataBase\n";
    out << "-------------------------\n";
    menuCall("1 carInput.dat", dealer, out);

    out << "\n\nAdd a car\n";
    out << "------------\n";
    menuCall("2 56789 Mitsubishi Galant 25000 7300", dealer, out);
    menuCall("4 56789", dealer, out);

    out << "\n\nDelete a car\n";
    out << "---------------\n";
    menuCall("3 23456", dealer, out);

    out << "\n\nDelete a car\n";
    out << "---------------\n" << dealer;
    menuCall("4 23456", dealer, out);

    out << "\n\nRetrieve a car and print it\n";
    out << "-------------------------------\n";
    menuCall("4 34567", dealer, out);

    out << "\n\nUpdate the car cost\n";
    out << "------------------------\n";
    menuCall("5 45678 90000", dealer, out);
    menuCall("4 45678", dealer, out);

    out << "\n\nPrint the DataBase in ascending order \n ";
    out << "-----------------------\n";
    menuCall("6", dealer, out);

    out << "\n\nQuit\n";
    out << "-------\n";
    menuCall("7", dealer, out);
    out.close();
}

/*
 * Function: parseOption()
 *
 * Param: menuInput - The input line from the menu.
 * Return: The first integer in the menuInput.
 */
int parseOption(string &menuInput) {
    stringstream ss;
    int option;
    ss << menuInput[0];
    ss >> option;
    cout << "parseOption: Input: " << option << endl;
    return option;
}

/*
 * Function: parseCar()
 *
 * Param: input - The input line to parse a car from.
 * Param: type - The method to use to parse the car.
 *      Valid options include:
 *          0, When reading from a file
 *          1, When reading all information for a car.
 *          2, When reading just the id for a car.
 * Return: The resulting car parsed from the input.
 */
Automobile parseCar(string &input, int type) {
    stringstream ss;
    ss << input;
    int option, id, mileage, cost;
    string make, model;
    Automobile automobile;
    switch(type) {
    case 0:
        ss >> id >> make >> model >> mileage >> cost;
        automobile.setId(id);
        automobile.setMake(make);
        automobile.setModel(model);
        automobile.setMileage(mileage);
        automobile.setCost(cost);
        cout << "parseCar[FILE]: " << automobile << endl;
        break;
    case 1:
        ss >> option >> id >> make >> model >> mileage >> cost;
        automobile.setId(id);
        automobile.setMake(make);
        automobile.setModel(model);
        automobile.setMileage(mileage);
        automobile.setCost(cost);
        cout << "parseCar[FULL]: " << automobile << endl;
        break;
    case 2:
        ss >> option >> id;
        automobile.setId(id);
        cout << "parseCar[ID]: " << automobile << endl;
        break;
    }
    return automobile;
}

/*
 * Function: parseFile()
 *
 * Param: menuInput - The input line from the menu.
 * Param: dealer - The Dealership to add the processed
 *      cars to.
 */
void parseFile(string &menuInput, Dealership &dealer) {
    stringstream ss;
    ifstream file;
    int option;
    char cstring[64];
    string filename, line;

    ss << menuInput;
    ss >> option >> filename;

    file.open(filename.c_str());
    while(file.getline(cstring, 64)) {
        line = cstring;
        dealer.addCar(parseCar(line, 0));
    }
}

/*
 * Function: menuCall()
 *
 * Param: arg - The input line for the menu to read.
 * Param: dealer - The Dealership to being modified.
 * Param: out - The stream to write the output to.
 */
void menuCall(string arg, Dealership &dealer, ofstream &out) {
    stringstream ss;
    Automobile automobile;
    out << "Input: " << arg << endl;
    switch(parseOption(arg)) {
    case 1: // Read from file
        parseFile(arg, dealer);
        break;
    case 2: // Add a car
        automobile = parseCar(arg, 1);
        if(!dealer.addCar(automobile)) {
            out << "Car id already taken: " << automobile << endl;
        } else {
            out << "Car added: " << automobile << endl;
        }
        break;
    case 3: // Delete a car
        automobile = parseCar(arg, 2);
        if(dealer.deleteCar(automobile)) {
            out << "Car deleted: " << automobile << endl;
        } else {
            out << "Car not deleted." << endl;
        }
        break;
    case 4: // Retrieve a car and print
        automobile = parseCar(arg, 2);
        if(dealer.retrieveCar(automobile)) {
            out << "Car found: " << automobile << endl;
        } else {
            out << "Car not found." << endl;
        }
        break;
    case 5: // Update a car
        ss << arg;
        int option, id, cost;
        ss >> option >> id >> cost;
        automobile.setId(id);
        dealer.retrieveCar(automobile);
        dealer.deleteCar(automobile);
        automobile.setCost(cost);
        dealer.addCar(automobile);
        break;
    case 6: // Print in assending order
        out << dealer;
        break;
    case 7: // Exit
        break;
    }
    cout << endl;
}
