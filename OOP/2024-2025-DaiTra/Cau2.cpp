#include <iostream>
#include <vector>
using namespace std;

class ICustomer
{
public:
    virtual void update(string message) = 0;
};

class IStore
{
public:
    virtual void addCustomer(ICustomer* cust) = 0;
    virtual void removeCustomer(ICustomer* cust) = 0;
    virtual void notifyCustomer(string message) = 0;
};

class ConcreteStore : public IStore
{
protected:
    vector<ICustomer*> customers;
public:
    void addCustomer(ICustomer* cust) override {
        customers.push_back(cust);
    }

    void removeCustomer(ICustomer* cust) override {
        for (auto it = customers.begin(); it != customers.end(); it++) {
            if (*it == cust) {
                customers.erase(it);
                break;
            }
        }
    }

    void notifyCustomer(string message) override {
        for (ICustomer* c : customers) {
            c->update(message);
        }
    }
};

class ConcreteCustomer : public ICustomer
{
public:
    void update(string message) override {
        cout << message << "\n";
    }
};

int main()
{
    ConcreteStore store;

    ConcreteCustomer c1;
    ConcreteCustomer c2;
    ConcreteCustomer c3;
    store.addCustomer(&c1);
    store.addCustomer(&c2);
    store.addCustomer(&c3);

    store.notifyCustomer("Notify 1");

    store.removeCustomer(&c2);
    store.notifyCustomer("Notify 2");

    return 0;
}