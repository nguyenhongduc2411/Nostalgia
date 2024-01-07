#include <iostream>
using namespace std;

struct Beverage {
    Beverage() { cout << "Make new beverage.\n"; }
    Beverage(const Beverage& b) { cout << "Copy beverage.\n"; }
};

struct Coffee : public Beverage {
    Coffee() { cout << "Make new coffee.\n"; }
    Coffee(const Coffee& b) { cout << "Copy coffee.\n"; }
};

struct Cappuchino : public Coffee {
    Cappuchino() { cout << "Make new cappuchino.\n"; }
    // Cappuchino(const Cappuchino& b) { cout << "Copy cappuchino.\n"; }
};

int main() {
    Cappuchino c1;
    cout << "\n";
    Cappuchino c2(c1);
}