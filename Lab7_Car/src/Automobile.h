#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_
#include <string>

using namespace std;

class Automobile {
public:
    Automobile(string &mId, string &mMake, string &mModel, int &mMileage, float &mCost);
    virtual ~Automobile();
    void setId(string argId);
    void setMake(string argMake);
    void setModel(string argModel);
    void setMileage(int argMileage);
    void setCost(float argCost);
    string getId();
    string getMake();
    string getModel();
    int getMileage();
    float getCost();
private:
    string mId;
    string mMake;
    string mModel;
    int mMileage;
    float mCost;
};

#endif /* AUTOMOBILE_H_ */
