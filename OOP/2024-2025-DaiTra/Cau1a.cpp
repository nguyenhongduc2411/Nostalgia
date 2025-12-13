#include <iostream>
using namespace std;

class Base
{
protected:
    int _protected;
private:
    int _private;
public:
    Base(int value) {
        _protected = _private = value;
    }
};

class Derived : public Base
{
public:
    void print() {
        cout << "Protected " << _protected << "\n";
        // cout << "Private " << _private << "\n"; // Báo lỗi biên dịch
    }
};

int main()
{
    Derived d(5);
    d.print();
    
    // d._protected;
    // d._private;

    return 0;
}