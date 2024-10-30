#include <iostream>

using namespace std;

#include "kolos.h"

unsigned int CHeavyVehicle::WeightLimit = 40;

int main()
{
    unsigned int CurrentLorryWeight = 39;
    CVehicle* pLorry = new CLorry(CurrentLorryWeight);

    if(pLorry->getWeightLimit() != 40)
    {
        cerr << "Result 1 is wrong" << endl;
        return -1;
    }


    CHeavyVehicle::setLimit(35);

        if(pLorry->getWeightLimit() != 35)
        {
            cerr << "Result 2 is wrong" << endl;
            return -1;
        }


        if(!pLorry->checkWeight())
        {
            cout << "Weight limit exceeded" << endl;
        }
        else
        {
            cerr << "Result 3 is wrong" << endl;
            return -1;
        }


    delete pLorry;

    return 0;
}