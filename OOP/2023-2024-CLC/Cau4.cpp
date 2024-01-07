#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class CurrencyFormatStrategy
{
public:
    virtual string format(long long money) = 0;
};

class ViVnCurrencyFormatStrategy : public CurrencyFormatStrategy
{
public:
    string format(long long money) {
        string s = "ViVnFormatted(" + to_string(money) + ")";
        return s;
    }
};

class EnUsCurrencyFormatStrategy : public CurrencyFormatStrategy
{
public:
    string format(long long money) {
        string s = "EnUsFormatted(" + to_string(money) + ")";
        return s;
    }
};

class CurrencyFormatter
{
private:
    CurrencyFormatStrategy* strategy;
public:
    void setStrategy(CurrencyFormatStrategy* strategy) {
        this->strategy = strategy;
    }

    string format(long long money) {
        return strategy->format(money);
    }
};

class LayoutItem
{
public:
    virtual map<string, string> getInfo() = 0;
};

class LayoutStrategy
{
protected:
    vector<LayoutItem*> layoutItems;
    vector<string> attributeNames;
public:
    virtual void print() = 0;

    void addItem(LayoutItem* item) {
        layoutItems.push_back(item);
    }

    void setAttributeNames(vector<string>& attributeNames) {
        this->attributeNames = attributeNames;
    }
};

class SimpleLayoutStrategy : public LayoutStrategy
{
public:
    void print() {
        for (int i = 0; i < layoutItems.size(); i++) {
            LayoutItem* layoutItem = layoutItems[i];

            map<string, string> info = layoutItem->getInfo();
            
            for (int j = 0; j < attributeNames.size(); j++) {
                string attributeName = attributeNames[j];
                cout << info[attributeName];

                if (j + 1 < attributeNames.size())
                    cout << " - ";
            }
            cout << "\n";
        }
    }
};

class TableLayoutStrategy : public LayoutStrategy
{
public:
    void print() {
        for (int j = 0; j < attributeNames.size(); j++) {
            string attributeName = attributeNames[j];
            cout << attributeName << "\t|\t";
        }
        cout << "\n";

        for (int i = 0; i < layoutItems.size(); i++) {
            LayoutItem* layoutItem = layoutItems[i];

            map<string, string> info = layoutItem->getInfo();
            
            for (int j = 0; j < attributeNames.size(); j++) {
                string attributeName = attributeNames[j];
                cout << info[attributeName];

                if (j + 1 < attributeNames.size())
                    cout << "\t-\t";
            }
            cout << "\n";
        }
    }
};

class Layouter
{
private:
    LayoutStrategy* strategy;
public:
    void setStrategy(LayoutStrategy* strategy) {
        this->strategy = strategy;
    }

    void print() {
        strategy->print();
    }

    void addItem(LayoutItem* item) {
        strategy->addItem(item);
    }

    void setAttributeNames(vector<string>& attributeNames) {
        strategy->setAttributeNames(attributeNames);
    }
};

class Mobile : public LayoutItem
{
private:
    string name;
    long long price;
    CurrencyFormatter* currencyFormatter;
public:
    Mobile(string name, long long price) {
        this->name = name;
        this->price = price;
    }

    void print() {
        cout << name << " - " << currencyFormatter->format(price);
    }

    void setCurrencyFormatter(CurrencyFormatter* currencyFormatter) {
        this->currencyFormatter = currencyFormatter;
    }

    map<string, string> getInfo() {
        map<string, string> info;
        info["Name"] = name;
        info["Price"] = currencyFormatter->format(price);
        return info;
    }
};

class Crawler
{
private:
    const char* url;
public:
    Crawler(const char* url) {
        this->url = url;
    }

    vector<Mobile*> execute() {
        vector<Mobile*> list;
        list.push_back(new Mobile("iPhone 11 64GB", 8950000));
        list.push_back(new Mobile("iPhone 12 128GB", 12500000));
        list.push_back(new Mobile("iPhone 13 Pro Max 256 GB", 18990000));
        list.push_back(new Mobile("iPhone 14 Pro 512GB", 23790000));
        return list;
    }
};

int main()
{
    const char* url = "mobiles.com/iphone";
    Crawler* task = new Crawler(url);
    vector<Mobile*> items = task->execute();

    cout << "Crawled " << items.size() << " phones from " << url << "\n";

    CurrencyFormatter* currencyFormatter = new CurrencyFormatter();
    CurrencyFormatStrategy* strategy = new ViVnCurrencyFormatStrategy();
    currencyFormatter->setStrategy(strategy);

    Layouter* layouter = new Layouter();
    LayoutStrategy* layoutStrategy = new SimpleLayoutStrategy();
    layouter->setStrategy(layoutStrategy);

    vector<string> attributeNames = {"Name", "Price"};
    layouter->setAttributeNames(attributeNames);
    
    for (Mobile* mobile : items) {
        mobile->setCurrencyFormatter(currencyFormatter);
        layouter->addItem(mobile);
    }
    layouter->print();

    // for (Mobile* mobile : items) {
    //     mobile->setCurrencyFormatter(currencyFormatter);
    //     mobile->print();
    //     cout << "\n";
    // }

    return 0;
}