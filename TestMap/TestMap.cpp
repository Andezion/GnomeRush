#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef unsigned int ID;
typedef string Title;

struct Employee
{
    string name;
    string position;
    int age;

    Employee() : name(""), position(""), age(0) {}
    Employee(string  n, string  pos, int a) : name(move(n)), position(move(pos)), age(a) {}
};

struct Books
{
    string writer;
    string type;
    int pages;
    string status;

    Books() : writer(""), type(""), pages(0), status("") {}
    Books(string m, string t, int b, string f) : writer(move(m)), type(move(t)), pages(b), status(move(f)) {}
};

typedef map<ID, Employee> Database;
typedef map<Title, Books> New_Database;

void addEmployees(Database& database);
void modifyEmployees(Database& database);

void addBooks(New_Database& database);
void modifyBooks(New_Database& database);

int main()
{
    Database database;
    addEmployees(database); // добавляем новых челов
    Database newDatabase = database;  // копию создаём

    // добавляем нового товарища
    newDatabase.insert(make_pair(787878, Employee("Vlad Grimm", "boss", 122)));

    modifyEmployees(newDatabase); // идём через модификацию

    cout << "Original database:" << endl;
    for (const auto& entry : database)
    {
        cout << "ID: " << entry.first << ", Employee: " << entry.second.name << ", Position: " << entry.second.position << ", Age: " << entry.second.age << endl;
    }

    cout << "\nModified database:" << endl;
    for (const auto& entry : newDatabase)
    {
        cout << "ID: " << entry.first << ", Employee: " << entry.second.name << ", Position: " << entry.second.position << ", Age: " << entry.second.age << endl;
    }

    database = newDatabase;  // обновляем

    cout << "\nDatabase after the assignment:" << endl;
    for (const auto& entry : database)
    {
        cout << "ID: " << entry.first << ", Employee: " << entry.second.name << ", Position: " << entry.second.position << ", Age: " << entry.second.age << endl;
    }

    New_Database new_database;
    addBooks(new_database);

    New_Database new_new_database = new_database;
    new_new_database.insert(make_pair("1984",Books("Orwell", "drama", 400, "taken")));

    modifyBooks(new_new_database);

    cout << "\nOriginal database:" << endl;
    for (const auto& entry : new_database)
    {
        cout << "Name: " << entry.first << ", Writer: " << entry.second.writer << ", Type: " << entry.second.type << ", Pages: " << entry.second.pages << ", Type: " << entry.second.type << endl;
    }

    cout << "\nModified database:" << endl;
    for (const auto& entry : new_new_database)
    {
        cout << "Name: " << entry.first << ", Writer: " << entry.second.writer << ", Type: " << entry.second.type << ", Pages: " << entry.second.pages << ", Type: " << entry.second.type << endl;
    }

    new_database = new_new_database;  // обновляем

    cout << "\nDatabase after the assignment:" << endl;
    for (const auto& entry : new_database)
    {
        cout << "Name: " << entry.first << ", Writer: " << entry.second.writer << ", Type: " << entry.second.type << ", Pages: " << entry.second.pages << ", Type: " << entry.second.type << endl;
    }

    return 0;
}

void addBooks(New_Database& database)
{
    database["Harry Potter"] = Books("Ernestik", "comedy", 234, "taken");
    database["Hobbit"] = Books("Timurchik", "documentary", 600, "not taken");
    database["WEEiA"] = Books("Slavon", "horror", 2000, "not taken");
}

void modifyBooks(New_Database& database)
{
    auto it = database.find("Hobbit");
    if(it != database.end())
    {
        it->second.status = "taken";
    }

    it = database.find("WEEiA");
    if(it != database.end())
    {
        it->second.writer = "satan";
    }
}

void addEmployees(Database& database)
{
    database[123456] = Employee("Ernest Jew", "burglar", 12);
    database[654321] = Employee("Timur Hus", "hacker", 666);
    database[111555] = Employee("Slava Green", "playboy", 7);
}

void modifyEmployees(Database& database)
{
    auto it = database.find(654321);
    if (it != database.end())
    {
        it->second.position = "president";
    }

    it = database.find(123456);
    if (it != database.end())
    {
        it->second.age = 29;
    }
}
