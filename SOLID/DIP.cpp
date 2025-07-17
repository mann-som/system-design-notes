/*

Dependecy inversion principle : class should depend on interface rather than concrete class

*/
#include <iostream>
#include <string>
using namespace std;

class ISaver {
public:
    virtual void save(const std::string& data) = 0;
    virtual ~ISaver() = default;
};

class FileSaver : public ISaver {
public:
    void save(const std::string& data) override {
        std::cout << "Saving to file: " << data << std::endl;
    }
};

class DatabaseSaver : public ISaver {
public:
    void save(const std::string& data) override {
        std::cout << "Saving to database: " << data << std::endl;
    }
};

class Report {
    ISaver& saver;

public:
    Report(ISaver& saverRef) : saver(saverRef) {}

    void generate() {
        saver.save("Report Data");
    }
};

int main() {
    FileSaver fs;
    Report report1(fs);
    report1.generate();

    DatabaseSaver ds;
    Report report2(ds);
    report2.generate();
}


