#include <iostream>

using namespace std;

void lesson_1()
{
    int i = 0; // int i {0};

    cout << i << endl;

    char letter = 'c';
    bool is = false;

    cout << letter << endl;
    cout << is << endl;

    float f = 1.284f;
    double d = 123.123;

    int arr[5] = {1,2,3,4,5}; // int arr[5] {1,2,3,4,5};

    cout << f << endl;
    cout << d << endl;

    cout << f << ' ' << d << " Hello" << endl;
}
void lesson_2()
{
    /*int age;
    cout << "Enter your age: ";

    cin >> age;

    cout << "\nYour age is: " << age << endl;

    char name[51];
    cout << "What is your name: ";
    cin >> name;

    cout << "\nYour name is: " << name << endl;*/

    char fullname[512];
    cout << "What is your name: ";
    cin.getline(fullname, 64, '\n');

    cout << "\nYour real name is: " << fullname << endl;
}
int lesson_3(int a, int b)
{
    return a + b;
}
void lesson_4()
{
    int a1;
    int a2 = 0;
    int a3(5);
    string s1;
    string s2("C++");

    char d1[8];
    char d2[8] = {'\0'};
    char d3[8] = {'a', 'b', 'c', 'd'};
    char d4[8] = {"abcd"};

    int b1{};

    char e1[8]{};
    char e2[8]{"Hello"};

    int *p1 = new int{};
    char *p2 = new char[8]{};
    char *p3 = new char[8]{"Hello"};

    cout << p3 << endl;
}
void lesson_5()
{
    int x = 10;

    cout << &x << endl;

    void *ptr = &x;
    cout << ptr << endl;

    int a = 10;
    int *point = &a;
    *point = 5;

    int y = *point;

    cout << y << endl;
    cout << a << endl;

    int b = 10;
    cout << &b << endl;
    void *pointer = nullptr;
    cout << pointer << "\n";
}
int Add(const int *a, const int *b)
{
    int c = *a + *b;
    return c;
}
void AddVal(const int *a, const int *b, int *result)
{
    *result = *a + *b;
}
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Factorial(const int *a, int *result)
{
    int helper = 0;
    while(helper != *a)
    {
        *result = *result + *result * helper;
        helper++;
    }
}


int main()
{
    int x = 10;
    int &ref = x;
    ref = 6;
    cout << &x << " " << &ref << endl;

    return 0;
}
