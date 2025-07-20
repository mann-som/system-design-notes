#include <iostream>
using namespace std;


// BAD DESIGN
// class Invoice{
//     public:
//         void applyDiscount(string type){
//             if(type == "festival"){
//                 // 
//             }
//             else if (type == "clearance"){
//                 // 
//             }
//             else{
//                 // 
//             }
//         }
// };

// implementation of strategy design pattern:

class DiscountStrategy{
    public:
        virtual void apply() = 0;
};

class FestivalDiscount : public DiscountStrategy{
    public:
        void apply() override{
            // 
        }

};

class clearanceDiscount : public DiscountStrategy{
    public:
        void apply() override{
            // 
        }
};

class Invoice{
    DiscountStrategy *strategy;
    public:
        Invoice(DiscountStrategy* strategy) : strategy(strategy){};

        void applyDiscout(){
            strategy->apply();
        }
};

/*

Workflow:
You create a discount class (FestivalDiscount, ClearanceDiscount) that knows how to apply itself.

You pass the desired strategy to Invoice dynamically, not hardcoded.

Invoice only uses the strategy — it doesn’t care what it does.

Want a new discount? → Just create a new class, no need to touch Invoice.

Code becomes modular, reusable, and testable.


the FestivalDiscount/ClearanceDiscount "is-a" relationship with DiscountStrategy. this is-a relationship, which means they inherited
the DiscountStrategy, allow the dynamic using or known as POLYMORPHISM

*/ 