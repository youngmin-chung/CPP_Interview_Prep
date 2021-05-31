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
    int PersonId;


    // Default constructor
    Person(){
        PersonId = 150515;
    }

    // Default values
    /*
    int func(int a, int b = 3){
        x = a;
        y = b;
        return a + b;

    }
    int main() {
        w = func(4);
        z = func(4, 5);

    }
    */
    // add virtual keyword here
    virtual void aboutMe(){
        cout << "I am a person.";
    }
    // virtual addCourse() here
    virtual bool addCourse(string s) = 0;

    // virtual destructor
    ~Person(){
        cout << "Deleting a person." << endl;
    }
};

class Student : public Person {
public:
    void aboutMe(){
        cout << "I am a student.";
    }

    // addCourse() here
    bool addCourse(string s) {
        cout << "Added course " << s << " to student." << endl;
        return true;
    }

    ~Student(){
        cout << "Deleting a student." << endl;
    }
};

int main()
{

    //Person * p  = new Person();
    //p->aboutMe(); // prints "I am a person."
    //delete p; // Important! Make sure to declare allocated memory.
    //cout << "\n\n";

    Student * s  = new Student();
    s->aboutMe(); // prints "I am a student."
    delete s; // Important! Make sure to declare allocated memory.
    cout << "\n\n";
    // Virtual Functions
    Person * vP = new Student();
    vP->aboutMe();
    // print out "I am a person" here. The reason why aboutMe() resolved at compile time,
    // in a mechanism known as static binding.
    // Solution: ADD 'virtual' keyword to Person class

    // Virtual Function Usage 2: we can't implement a method for the parent class
    /*
    * For example, we want Student and Teacher to inherit from Parent so that we can implement
    * a common method such as addCourse(string s). Calling addCourse on Person, however, wouldn't
    * make much sense since the implementation on whether the object is actually a Student or Teatcher
    */
    cout << "\n\n";
    vP->addCourse("History");
    delete vP; // Important! Make sure to declare allocated memory. // prints "Deleting a person."
    cout << "\n\n";
    // Test constructor
    // cout << "Test Default constructor\n";
    // Person y;
    // cout << "Person ID is "<< y.PersonId <<"\n";



    // Pointers and References
    cout << "Example of Pointers\n";
    int * p = new int;
    *p = 7;
    int * q = p;
    *p = 8;
    cout << "Result is " << *q; // prints 8
    cout << "\n\nExample of References\n";
    int a = 5;
    int & b = a;
    b = 7;
    cout << "Result is " << a; // prints 7

    cout << "\n\nExample of Pointer Arithmetic\n";
    int * pa = new int[2];
    pa[0] = 0;
    pa[1] = 1;
    pa++;
    cout << *pa; // Outputs 1










    return 0;
}

/*
* Templates are a way of reusing code to apply the same class to different
* For example, we might have a list-like data structure which we would like to
* use for lists of various types. The code below implements this with the
* ShiftedList class.
*/

template <class T> class ShiftedList {
    T* array;
    int offset, size;
public:
    ShiftedList(int sz) : offset(0), size(sz){
        array = new T[size];
    }
    ~ShiftedList() {
        delete [] array;
    }

    void shiftBy(int n ){
        offset = (offset + n) % size;
    }

    T getAt(int i){
        return array[convertIndex(i)];
    }

    void setAt(T item, int i){
        array[convertIndex(i)] = item;
    }

private:
    int convertIndex(int i){
        int index = (i - offset) % size;
        while(index < 0) index += size;
        return index;
    }
};
