#include <iostream>
#include <string>
using namespace std;

/*

#SINGLE RESPONSIBLITY PRINCIPLE:

-> every class should have only 1 reason to change
-> every class should handle one kind of task

->  a market entity should have information and methods for the marker for example, colour, price per unit and year of mfg. 
    what it should not have?
    for example: handling invoice, handling logic of downloading the invoice/bill

*/

class Marker{
    int price;
    string colour;
    public:
        Marker(int _price, string _colour): price(_price), colour(_colour){}

        void setPrice(int price){
            this->price = price;
        }

        int getPrice(){
            return price;
        }

        void setColour(string colour){
            this->colour = colour;
        }

        // int invoice(int quantity){
        //     return price*quantity;                        ----> these methods shouldn't be handled by the Marker class
        // }

        // void saveToDB(){
        //     // logic
        // }
        
};

class Invoice{
    Marker marker;
    int quantity;
    public:
        Invoice(Marker marker, int quantity): marker(marker), quantity(quantity){};
        

        int calculateTotal(){
            int price = ((marker.getPrice() *this->quantity));
            return price;
        }


        // void saveToDB(){
        //     // logic            ----> even this class stil have 2 reason to change that is invoice logic and save logic. 
        // }

        // void saveToPdf(){
        //     // 
        // }
};

class InvoiceDao{

    Invoice invoice;
    public:
        InvoiceDao(Invoice invoice): invoice(invoice){}

        void saveToDB(){                                    //NOW ALL CLASSES FOLLOW SRP. EVERY CLASS HAVE ONLY 1 REASON TO CHANGE
            // logic
        }

};

/*
Now if we see every class, have only one reason to change:
1. Marker -> just the info and methods of Marker
2. Invoice -> just the logic to handle invoice calculation
3. InvoiceDAO -> just the logic to generate and save invoices
*/

int main(){
    return 0;
}