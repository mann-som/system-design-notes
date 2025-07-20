/*
OPEN FOR EXTENSION BUT CLOSE FOR MODIFICATION



*/

#include <iostream>
#include <string>
using namespace std;

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

};

class InvoiceDao{

    Invoice invoice;
    public:
        InvoiceDao(Invoice invoice): invoice(invoice){}

        void processingTheInvoice(){                                   
            // logic                                                    //Let's say this part of code is tested and live. so IF WE WANT TO ADD MORE FUNCTIONALITY 
                                                                        // WE SHOULDN'T MODIFY THIS EXISTING CLASS BUT EXTEND IT
        }

};

class iInvoiceDao {
public:
    virtual void save(const Invoice& invoice) = 0;
};

class DatabaseInvoiceDao : public iInvoiceDao {
public:
    void save(const Invoice& invoice) override {
        cout << "Saving invoice to DB..." << endl;
    }
};

class FileInvoiceDao : public iInvoiceDao {
public:
    void save(const Invoice& invoice) override {
        cout << "Saving invoice to file..." << endl;
    }
};

// New class that depends on abstraction
class InvoiceProcessor {
    iInvoiceDao* dao;
public:
    InvoiceProcessor(iInvoiceDao* dao): dao(dao) {}

    void process(const Invoice& invoice) {
        // logic to process invoice
        dao->save(invoice);  // Open for extension (new save methods), closed for modification
    }
};

int main() {
    Marker marker(50, "Blue");
    Invoice invoice(marker, 3);

    // Choose to save to DB
    iInvoiceDao* dbDao = new DatabaseInvoiceDao();

    // Or choose to save to file
    iInvoiceDao* fileDao = new FileInvoiceDao();

    // Inject whichever you want into the processor
    InvoiceProcessor processor(dbDao);   // or InvoiceProcessor processor(fileDao);
    processor.process(invoice);

    delete dbDao;
    delete fileDao;

    return 0;
}
