/*
 * Class and Inheritance
 */

#include <iostream>

using namespace std;

#define NAME_SIZE 50 // Defines a marco

class Person {
    int id; // all members are private by default
    char name[NAME_SIZE];

public:
    void aboutMe(){
        cout << "I am a person.";
    }
};

class Student : public Person {
public:
    void aboutMe(){
        cout << "I am a student.";
    }
};

int main()
{
    Person * p  = new Person();
    Student * s  = new Student();
    p->aboutMe(); // prints "I am a person."
    cout << "\n";
    s->aboutMe(); // prints "I am a student."
    delete p; // Important! Make sure to declare allocated memory.
    delete s; // Important! Make sure to declare allocated memory.


    return 0;
}
