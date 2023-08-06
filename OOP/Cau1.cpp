#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Mobile
{
private:
    string code;
    string name;
    string brand;
    string mfgDate; // day/month/year (05/08/2023)
public:
    Mobile()
    {

    }

    Mobile(string code, string name, string brand, string mfgDate)
    {
        this->code = code;
        this->name = name;
        this->brand = brand;
        this->mfgDate = mfgDate;
    }

    friend istream& operator>>(istream& in, Mobile& mobile)
    {
        in >> mobile.code;
        in >> mobile.name;
        in >> mobile.brand;
        in >> mobile.mfgDate;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Mobile& mobile)
    {
        out << "Code: " << mobile.code << "\n";
        out << "Name: " << mobile.name << "\n";
        out << "Brand: " << mobile.brand << "\n";
        out << "Manufacturing date: " << mobile.mfgDate << "\n";
        return out;
    }

    static int compare(const Mobile& a, const Mobile & b)
    {
        bool isLess = compareLess(a, b);

        if (isLess)
            return -1; // a < b
        
        bool isGreater = compareLess(b, a);

        if (isGreater)
            return 1; // a > b
        
        return 0; // a == b
    }

    static bool compareLess(const Mobile& a, const Mobile& b)
    {
        int dayA = stoi(a.mfgDate.substr(0, 2));
        int monthA = stoi(a.mfgDate.substr(3, 2));
        int yearA = stoi(a.mfgDate.substr(6));

        int dayB = stoi(b.mfgDate.substr(0, 2));
        int monthB = stoi(b.mfgDate.substr(3, 2));
        int yearB = stoi(b.mfgDate.substr(6));

        if (yearA != yearB)
            return yearA < yearB;

        if (monthA != monthB)
            return monthA < monthB;

        return dayA < dayB;
    }

    bool operator<(const Mobile& other)
    {
        return compare(*this, other) == -1;
    }

    bool operator>(const Mobile & other)
    {
        return compare(*this, other) == 1;
    }

    bool operator==(const Mobile & other)
    {
        return compare(*this, other) == 0;
    }

    bool operator!=(const Mobile & other)
    {
        return !(*this == other);
    }
};

int main()
{
    // Mobile mobile;
    // cin >> mobile;
    // cout << mobile;

    vector<Mobile> mobiles = {
        Mobile("111", "AAA", "BBB", "05/08/2023"),
        Mobile("222", "CCC", "DDD", "05/08/2022"),
        Mobile("333", "CCC", "DDD", "05/07/2023"),
        Mobile("444", "CCC", "DDD", "04/08/2022"),
        Mobile("555", "AAA", "BBB", "05/08/2023"),
    };

    // sort(mobiles.begin(), mobiles.end());
    sort(mobiles.begin(), mobiles.end(), Mobile::compareLess);

    for (int i = 0; i < mobiles.size(); i++)
    {
        cout << mobiles[i] << "\n";
    }

    cout << (mobiles[mobiles.size() - 1] != mobiles[mobiles.size() - 1]);

    return 0;
}