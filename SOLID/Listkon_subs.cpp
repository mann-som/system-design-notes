/*

L of SOLID: Liskov substitute principle
if class B is subtype of class A, then we should be able to replace object of A with B without breaking the behaviour of program.
*/

#include <iostream>
using namespace std;

class iBike{
    virtual void turnOnEngine() = 0;
    virtual void accelerate() = 0;
};

class Motorcycle: public iBike{

    bool isEngineOn;
    int speed;
    public:
        void turnOnEngine() override {
            isEngineOn = true;
        }

        void accelerate() override {
            speed += 10;
        }
};

class Bicycle: public iBike{
    int speed;
    public:
        void turnOnEngine() override{
            cout<<"Can't turn on engine"<<endl;      //   Both motorcycle and bicycle are inheriting iBike but both can have different implementation of same
                                                     //   function without breaking the program
        }
        void accelerate() override {
            speed++;   
        }
};