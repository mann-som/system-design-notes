#include <iostream>
#include <string>
using namespace std;

/*
TEMPLATES:
    - allows to write generic code that can work with any datatype.

    syntax : template <typename a, typename b, ...> 'typename' keyword can also be replaced by the keyword 'class' ---> template <class a, class b, ...>

    an instance of templates can be called like : entity_name<type1, type2> template parametes can be any data types

    template <typename T> T func(T x, T y){
    }                      -----------------------> this function means it can take one common datatype for x and y and it will return the
                                                    same data type back

    another form:

    template <typename T1, typename T2> void(T1 x, T2 y){
    }                      -----------------------> here x and y can be 2 different datat types and 'void' keyword define that it will not
                                                    return anything

*/

template <typename T1, typename T2>
void maxEle(T1 x, T2 y)
{
    cout << x << " is " << y << " years old" << endl;
    // return;
}

// CLASS TEMPLATE

template <typename T>
class classTemp
{

public:
    T x;
    T y;

    classTemp(T val1, T val2) : x(val1), y(val2) {}

    void printTemp()
    {
        cout << "X: " << x << " Y: " << y << endl;
    }
};

int main()
{

    string a = "mann";
    int b = 22;
    maxEle(a, b);

    // USING CLASS BASED TEMPLATE
    classTemp<int> intTest(10, 20);
    classTemp<string> stringTest("hello", "world");

    intTest.printTemp();
    stringTest.printTemp();
    return 0;
}