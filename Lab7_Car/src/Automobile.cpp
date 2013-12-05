#include "Automobile.h"

Automobile::Automobile(string &mId, string &mMake, string &mModel, int &mMileage, float &mCost) {
    this->mId = mId;
    this->mMake = mMake;
    this->mModel = mModel;
    this->mMileage = mMileage;
    this->mCost = mCost;
}

Automobile::~Automobile() {
    delete &mId;
    delete &mMake;
    delete &mModel;
    delete &mMileage;
    delete &mCost;
}

void Automobile::setId(string argId) {
    this->mId = argId;
}

void Automobile::setMake(string argMake) {
    this->mMake = argMake;
}

void Automobile::setModel(string argModel) {
    this->mModel = argModel;
}

void Automobile::setMileage(int argMileage) {
    this->mMileage = argMileage;
}

void Automobile::setCost(float argCost) {
    this->mCost = argCost;
}

string Automobile::getId() {
    return this->mId;
}

string Automobile::getMake() {
    return this->mMake;
}

string Automobile::getModel() {
    return this->mModel;
}

int Automobile::getMileage() {
    return this->mMileage;
}

float Automobile::getCost() {
    return this->mCost;
}
