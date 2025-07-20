#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Interface class (acts like an interface in Java)
class IPromotable {
public:
    virtual void askForPromotion() = 0;  // Pure virtual
    virtual ~IPromotable() = default;    // Virtual destructor for interface
};

// Base Employee class
class Employee : public IPromotable {
protected:
    string name;
    int age;
    string position;
    class Manager* manager;  // forward declaration, defined later

public:
    Employee(string n, int a, string pos, Manager* m)
        : name(n), age(a), position(pos), manager(m) {}

    virtual void askForPromotion() override {
        if (manager) {
            cout << name << " (Employee) is requesting promotion from " 
                 << manager->getName() << "." << endl;
        } else {
            cout << name << " (Employee) has no manager assigned!" << endl;
        }
    }

    string getName() const { return name; }
    virtual ~Employee() {}
};

// Manager class inherits from Employee
class Manager : public Employee {
private:
    vector<Employee*> team;

public:
    Manager(string n, int a, string pos)
        : Employee(n, a, pos, nullptr) {}

    void addTeamMember(Employee* emp) {
        team.push_back(emp);
    }

    string getName() const {
        return name;
    }

    void askForPromotion() override {
        cout << name << " (Manager) is initiating promotion review for team:\n";
        for (auto member : team) {
            cout << " - " << member->getName() << endl;
        }
    }

    void processTeamPromotions() {
        cout << name << " is processing promotions:\n";
        for (auto member : team) {
            member->askForPromotion();  // this will call their overridden method
        }
    }
};

int main() {
    Manager* mgrAlice = new Manager("Alice", 40, "Engineering Manager");

    Employee* empBob = new Employee("Bob", 28, "Software Engineer", mgrAlice);
    Employee* empCharlie = new Employee("Charlie", 30, "Data Scientist", mgrAlice);

    // Add team members to manager
    mgrAlice->addTeamMember(empBob);
    mgrAlice->addTeamMember(empCharlie);

    cout << "\n--- Individual Requests ---\n";
    empBob->askForPromotion();
    empCharlie->askForPromotion();
    mgrAlice->askForPromotion();

    cout << "\n--- Manager Initiates Promotion Processing ---\n";
    mgrAlice->processTeamPromotions();

    // Clean up
    delete empBob;
    delete empCharlie;
    delete mgrAlice;

    return 0;
}
