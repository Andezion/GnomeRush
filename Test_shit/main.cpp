#include <iostream>
#include <cstring>

using namespace std;

class EmptyStack
{

};

class CElement
{
private:
    int value;
public:
    CElement() : value(0) {}
    explicit CElement(int val) : value(val) {}
    int getValue() const { return value; }
};


class CStack
{
private:
    CElement *pData;
    unsigned int top;
    unsigned int size;

    void resize()
    {
        size_t newSize = size + 1;
        CElement *newData = new CElement[newSize];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = pData[i];
        }

        delete[] pData;
        pData = newData;
        size = newSize;
    }

public:
    CStack() : pData(nullptr), top(0), size(0) {}

    CStack(const CStack &other) : pData(nullptr), top(other.top), size(other.size)
    {
        pData = new CElement[size];
        for (unsigned int i = 0; i < top; i++)
        {
            pData[i] = other.pData[i];
        }
    }

    ~CStack()
    {
        delete[] pData;
    }

    void push(int val)
    {
        if (top == size)
        {
            resize();
        }
        pData[top] = CElement(val);
        top++;
    }

    int pop()
    {
        if (top == 0)
        {
            throw EmptyStack();
        }
        return pData[--top].getValue();
    }

    CStack &operator=(const CStack &other)
    {
        if (this != &other)
        {
            delete[] pData;
            top = other.top;
            size = other.size;
            pData = new CElement[size];

            for (unsigned int i = 0; i < top; i++)
            {
                pData[i] = other.pData[i];
            }
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const CStack &stack)
    {
        for (unsigned int i = stack.top; i > 0; i--)
        {
            os << stack.pData[i - 1].getValue() << " ";
        }
        return os;
    }


};


int main()
{

    return 0;
}
