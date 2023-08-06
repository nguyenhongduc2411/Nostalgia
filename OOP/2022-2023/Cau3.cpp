#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class ITableRowData
{
public:
    virtual vector<string> getCells() = 0;
};

class Table
{
private:
    vector<string> titles;
    vector<ITableRowData*> rows;
public:
    Table(vector<string> titles)
    {
        this->titles = titles;
    }

    void addRow(ITableRowData* row)
    {
        rows.push_back(row);
    }

    void print()
    {
        for (int i = 0; i < titles.size(); i++) {
            cout << titles[i] << "\t";
        }
        cout << "\n";
        for (int i = 0; i < rows.size(); i++) {
            ITableRowData* row = rows[i];
            vector<string> cells = row->getCells();
            for (int j = 0; j < cells.size(); j++) {
                cout << cells[j] << "\t";
            }
            cout << "\n";
        }
    }
};

class MoneyFormatter
{
private:
    inline static const string SEPARATOR = ",";
    inline static const string CURRENCY = "$";
    static const bool IS_CURRENCY_PREFIX = true;
public:
    static string format(int money)
    {
        return "Formatted(" + to_string(money) + " | " + SEPARATOR + " | " + CURRENCY
        + " | " + to_string(IS_CURRENCY_PREFIX) + ")";
    }
};

class Fund
{
protected:
    string type;
    string name;
public:
    Fund(string type, string name)
    {
        this->type = type;
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    virtual string getInfo() = 0;
};

class MoneyFund : public Fund
{
private:
    inline static const string TYPE_NAME = "Tien phap dinh";
    int months;
    int fundPerMonth;
public:
    MoneyFund(string name, int months, int fundPerMonth) : Fund(TYPE_NAME, name)
    {
        this->months = months;
        this->fundPerMonth = fundPerMonth;
    }

    int grantMoney()
    {
        return months * fundPerMonth;
    }

    int getMonths()
    {
        return months;
    }

    string getInfo()
    {
        return name + ": " + to_string(months) + " thang. ";
    }
};

class CryptoFund : public Fund
{
private:
    inline static const string TYPE_NAME = "Tien ma hoa crypto";
public:
    CryptoFund(string name) : Fund(TYPE_NAME, name)
    {
    }

    string getInfo()
    {
        return name + ": Thong tin ve tien crypto. ";
    }
};

class RoomFund : public Fund
{
private:
    inline static const string TYPE_NAME = "Tai tro van phong";
    string address;
public:
    RoomFund(string address, string name) : Fund(TYPE_NAME, name)
    {
        this->address = address;
    }

    string getInfo()
    {
        return "Dia chi: " + address + ", Phong: " + name + ". ";
    }
};

class MoneyFundsBonus
{
private:
    vector<MoneyFund*> moneyFunds;
    map<int, float> bonusFromMonth;
public:
    MoneyFundsBonus()
    {

    }

    void addMoneyFund(MoneyFund* moneyFund)
    {
        moneyFunds.push_back(moneyFund);
    }

    void addBonusFromMonth(int month, float bonusRate)
    {
        bonusFromMonth[month] = bonusRate;
    }

    int getBonus()
    {
        return 95000;
    }
};

class Project : public ITableRowData
{
protected:
    string type;
    string name;
    vector<Fund*> funds;
    MoneyFundsBonus moneyFundsBonus;

    static const int BONUS_FROM_MONTH = 7;
    inline static const float BONUS_RATE = 0.2f;
public:
    Project(string type, string name)
    {
        this->type = type;
        this->name = name;
        moneyFundsBonus.addBonusFromMonth(BONUS_FROM_MONTH, BONUS_RATE);
    }

    void addFund(Fund* fund)
    {
        funds.push_back(fund);
        if (MoneyFund* moneyFund = dynamic_cast<MoneyFund*>(fund))
        {
            moneyFundsBonus.addMoneyFund(moneyFund);
        }
    }

    int grantMoney()
    {
        int sum = 0;
        for (int i = 0; i < funds.size(); i++)
        {
            if (MoneyFund* fund = dynamic_cast<MoneyFund*>(funds[i]))
            {
                sum += fund->grantMoney();
            }
        }
        sum += moneyFundsBonus.getBonus();
        return sum;
    }

    void print()
    {
        string str;
        str += type + ": " + name + ". ";
        for (int i = 0; i < funds.size(); i++)
        {
            str += funds[i]->getInfo();
        }

        int sum = grantMoney();
        str += "Kinh phi: " + MoneyFormatter::format(sum);
        cout << str;
    }

    vector<string> getCells()
    {
        string info;
        for (int i = 0; i < funds.size(); i++)
        {
            info += funds[i]->getInfo();
        }
        int sum = grantMoney();
        return {type, name, info, MoneyFormatter::format(sum)};
    }

    ~Project()
    {
        for (int i = 0; i < funds.size(); i++)
        {
            delete funds[i];
        }
    }
};

class Idea : public Project
{
private:
    inline static const string TYPE_NAME = "Y tuong";
    static const int FUND_PER_MONTH = 20000000;
public:
    Idea(string name, int months) : Project(TYPE_NAME, name)
    {
        Fund* fund = new MoneyFund("Phat trien", months, FUND_PER_MONTH);
        Fund* fund2 = new CryptoFund("Bitcoin");
        Fund* fund3 = new RoomFund("Nguyen Van Cu", "E304");
        addFund(fund);
        addFund(fund2);
        addFund(fund3);
    }
};

class Mvp : public Project
{
private:
    inline static const string TYPE_NAME = "San pham";
    static const int OPERATING_FUND_PER_MONTH = 15000000;
    static const int MARKETING_FUND_PER_MONTH = 15000000;
public:
    Mvp(string name, int operatingMonths, int marketingMonths) : Project(TYPE_NAME, name)
    {
        Fund* operatingFund = new MoneyFund("Van hanh", operatingMonths, OPERATING_FUND_PER_MONTH);
        Fund* marketingFund = new MoneyFund("Marketing", marketingMonths, MARKETING_FUND_PER_MONTH);
        addFund(operatingFund);
        addFund(marketingFund);
    }
};

int main()
{
    vector<Project*> projects = {
        new Idea("SuperTech", 6),
        new Mvp("FutureCar", 6, 3),
        new Idea("VirtualHouse", 7),
        new Idea("NightVision", 4),
        new Mvp("Smartkey", 4, 5)
    };

    cout << "So du an: " << projects.size() << endl;
    int sum = 0;
    for (int i = 0; i < projects.size(); i++) {
        sum += projects[i]->grantMoney();
        cout << i + 1 << ". ";
        projects[i]->print();
        cout << endl;
    }
    cout << "Tong tien tai tro: " << MoneyFormatter::format(sum) << endl;

    Table t({"Loai du an", "Ten du an", "Thong tin", "Kinh phi"});
    for (int i = 0; i < projects.size(); i++) {
        t.addRow(projects[i]);
    }
    t.print();

    for (int i = 0; i < projects.size(); i++) {
        delete projects[i];
    }

    return 0;
}