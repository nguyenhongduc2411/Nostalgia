#include <iostream>
using namespace std;

class Base
{
public:
    virtual void print() {
        cout << "Print Base\n"; // 
    }

    // virtual void print2() = 0; // Pure virtual function
};

class Derived : public Base
{
public:
    void print() override { // Báo lỗi biên dịch nếu print không phải là virtual function
        cout << "Print Derived\n";
    }
};

// class Derived2 : public Derived
// {
// public:
//     void print() override {
//         cout << "Print Derived\n";
//     }

//     void print2() override {
//         cout << "Print2\n";
//     }
// };

int main()
{
    Base* a = new Derived();
    a->print(); // Print ra "Print Derived" khi có từ khóa virtual. Nếu không thì print ra "Print Base"

    return 0;
}