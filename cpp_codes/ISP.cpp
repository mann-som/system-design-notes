/*

I of SOLID: interface segmented principle

Interface should be such that, client should not implement unnecessary functions that they do not need 

*/

class iRestaurantEmployee{

    virtual void washDishes() = 0;
    virtual void serverCustomers() = 0;
    virtual void cookFood() = 0;
};

class waiter: public iRestaurantEmployee{

    public:
        void washDishes() override{
            //not my job
        }
        void serverCustomers() override{
            //my implementation                //////// here waiter is inherited from the restaurant employee interface so he have to implement its own
        }                                      //////// washDished, serverCustomers, cookFood. but it's not his job so we should have seperate interface for 
        void cookFood() override{                       //////// each of them according to their functionality/methods.
            //not my job
        }

};