#ifndef OOP4_2_KOLOS_H
#define OOP4_2_KOLOS_H

/*
Dokończyć (niczego nie zmieniając, jedynie dopisując) deklaracje klas Container
i ArrayContainer tak, żeby poprawnie działały w podanej funkcji main.
*/

#include <vector>

using namespace std;

class SortingNotImplemented {};

class Container
        {
public:
    virtual size_t getSize() = 0;
    virtual void insertAtBeginning(int value) = 0;
    virtual void addAtEnd(int value) = 0;
    virtual int getElement(int index) = 0;
    virtual void sortAscending() = 0;
    virtual void sortDescending() = 0;
    virtual ~Container() {};
};

class ArrayContainer: public Container
        {
private:
    vector<int> data;
public:
    size_t getSize()
    {
        return data.size();
    }

    void insertAtBeginning(int value)
    {
        data.insert(data.begin(), 1, value);
    }

    void addAtEnd(int value){
        data.push_back(value);
    }

    int getElement(int index){
        return data.at(index);
    }

    void sortAscending()
    {
        if(data.empty() || data.size() == 1)
        {
            return;
        }
        for (long unsigned int i = 0; i < data.size(); i++)
        {
            for (long unsigned int j = 0; j < data.size() - 1; j++)
            {
                if(data[j] > data[j+1])
                {
                    int tmp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = tmp;
                }
            }

        }
    }

    void sortDescending()
    {
        if(data.empty() || data.size() == 1)
        {
            return;
        }
        for (long unsigned int i = 0; i < data.size(); i++)
        {
            for (long unsigned int j = 0; j < data.size() - 1; j++)
            {
                if(data[j] < data[j+1])
                {
                    int tmp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = tmp;
                }
            }

        }
    }

};

#endif //OOP4_2_KOLOS_H
