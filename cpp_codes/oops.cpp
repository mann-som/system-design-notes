#include <iostream>
#include <vector>
using namespace std;

/*
OOPS CONCEPTS IN C++:

1. Encapsulation - Wrapping data and functions together (e.g., class, private + public + getters/setters)
2. Abstraction - Hiding internal logic and showing only necessary details (e.g., access modifiers + interfaces)
3. Inheritance - One class inherits properties/behaviour of another (e.g., class B : public A)
4. Polymorphism - Same function name, different behaviors (compile-time [function overloading], run-time [virtual function overriding])

-------------------------------------------------------
ACCESS MODIFIERS:

1. private - default for class members
    - Accessible only inside the class
2. public - accessible from anywhere (outside/inside class)
3. protected - like private, but accessible by derived classes

-------------------------------------------------------
CONSTRUCTOR & DESTRUCTOR:

1. Constructor
    - Same name as class, no return type
    - Used to initialize object
    - Can be overloaded
    - Can be parameterized or default

2. Destructor
    - Name starts with ~ (tilde)
    - No arguments, no return type
    - Automatically called when object is destroyed
*/

class iEmployee {
public:
    virtual void askForPromotion() = 0;  // Pure virtual function (interface behaviour)
    virtual ~iEmployee() {}              // Always add virtual destructor to interfaces
};

class Employee : public iEmployee {
private:
    string name, company;
    int age;

public:
    // Constructor:
    Employee(string n, string c, int a) : name(n), company(c), age(a) {}

    // Destructor:
    ~Employee() {
        cout << name << "'s object destroyed.\n";
    }

    // SETTER & GETTER (ENCAPSULATION):
    void setAge(int a) {
        if (a > 18) age = a;
        else cout << "Invalid age, must be > 18.\n";
    }

    int getAge() {
        return age;
    }

    // BEHAVIOUR:
    void introduction() {
        cout << "I am " << name << ", " << age << " years old, working at " << company << ".\n";
    }

    // INTERFACE IMPLEMENTATION (POLYMORPHISM):
    void askForPromotion() override {
        if (age > 30) cout << name << " is eligible for promotion.\n";
        else cout << name << " is not eligible yet.\n";
    }

    string getName() { return name; }
};

/*
INHERITANCE:
- Manager is-a Employee, but with extra capabilities (has a team)
- Manager overrides behavior of Employee

Syntax:
    class Derived : access Base
*/

class Manager : public Employee {
private:
    vector<Employee*> team;

public:
    Manager(string n, string c, int a) : Employee(n, c, a) {}

    void addTeamMember(Employee* e) {
        team.push_back(e);
    }

    void askForPromotion() override {
        cout << getName() << " is processing promotions for team:\n";
        for (auto emp : team) {
            emp->askForPromotion();
        }
    }
};

/*
STATIC MEMBERS:
- Shared across all objects of the class
*/

class Company {
public:
    static int totalEmployees;

    Company() {
        totalEmployees++;
    }

    static void showCount() {
        cout << "Total employees = " << totalEmployees << endl;
    }
};

int Company::totalEmployees = 0;

/*
OPERATOR OVERLOADING (optional intro):
- Allows user-defined behavior for operators like +, ==, etc.

Example:
    Overload + to add two Points
*/

class Point {
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    Point operator + (Point& p) {
        return Point(x + p.x, y + p.y);
    }

    void display() {
        cout << "(" << x << "," << y << ")\n";
    }
};

int main() {
    // Encapsulation + Constructor
    Employee emp1("Mann", "OpenAI", 22);
    emp1.introduction();
    emp1.askForPromotion();
    emp1.setAge(35);
    emp1.askForPromotion();

    // Inheritance + Polymorphism
    Employee* emp2 = new Employee("Shiv", "Google", 28);
    Employee* emp3 = new Employee("Aman", "Microsoft", 31);
    Manager* mgr = new Manager("Rahul", "Amazon", 40);

    mgr->addTeamMember(emp2);
    mgr->addTeamMember(emp3);

    cout << "\n--- Manager Promotion Check ---\n";
    mgr->askForPromotion();

    delete emp2;
    delete emp3;
    delete mgr;

    // Static example
    Company c1, c2, c3;
    Company::showCount();

    // Operator Overloading
    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;
    p3.display();
}
