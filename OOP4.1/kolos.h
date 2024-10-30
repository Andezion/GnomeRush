#ifndef OOP4_1_KOLOS_H
#define OOP4_1_KOLOS_H

using namespace std;

class CVehicle
{
private:
    unsigned int Weight;

public:
    virtual unsigned int getWeightLimit() = 0;

    bool checkWeight()
    {
        return Weight <= getWeightLimit();
    }

    void setWeight(int newWeight)
    {
        Weight = newWeight;
    }

    virtual ~CVehicle(){}
};

class CHeavyVehicle : public CVehicle
{
private:
    static unsigned int WeightLimit;

public:
    unsigned int getWeightLimit()
    {
        return WeightLimit;
    }
    static void setLimit(int newLimit)
    {
        WeightLimit = newLimit;
    }
};

class CLorry : public CHeavyVehicle
{
public:
    CLorry(int weight)
    {
        setWeight(weight);
    }

};

#endif //OOP4_1_KOLOS_H
