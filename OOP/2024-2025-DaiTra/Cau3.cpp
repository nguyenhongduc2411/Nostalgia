#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    static Date getCurrentDate();
};

class IRule
{
public:
    virtual string rename(const string& str) = 0;
};

class NormalizeCasing : public IRule
{
public:
    string rename(const string& str) override {
        return str;
    }
};

class RemoveSpecialCharacters : public IRule
{
private:
    std::regex regex;
public:
    RemoveSpecialCharacters(string pattern) {

    }

    string rename(const string& str) override {
        return str;
    }
};

class AddDatePrefix : public IRule
{
private:
    string dateFormat;
public:
    AddDatePrefix(string dateFormat) {

    }

    string rename(const string& str) override {
        return str;
    }
};

class Formatter
{
private:
    vector<IRule*> rules;
public:
    Formatter() = default;

    Formatter(string rulesFileName) {
        // string ruleName = "AddDatePrefix";
        // if (ruleName == "AddDatePrefix") {
        //     IRule* rule = new AddDatePrefix("yyyymmdd_");
        // }
        // else if (ruleName == "abc"){

        // }
        // Mở file có path là rulesFileName
        // Rồi thực hiện đọc và addRule vào rules
    }

    void addRule(IRule* rule) {
        rules.push_back(rule);
    }

    string rename(const string& str) {
        string result = str;
        for (IRule* rule : rules) {
            result = rule->rename(result);
        }
        return result;
    }
};

class RuleFactory
{

};

class RenameCVFileUseCase : public Formatter
{
public:
    RenameCVFileUseCase() {
        addRule(new NormalizeCasing());
        addRule(new RemoveSpecialCharacters("[-_/.]"));
        addRule(new AddDatePrefix("yyyymmdd_"));
    }

    RenameCVFileUseCase(string rulesFileName) : Formatter(rulesFileName) {}
};

int main()
{
    // RenameCVFileUseCase cvFileRenamer;
    RenameCVFileUseCase cvFileRenamer("rules.txt");

    string original = "ho so xin viec_nguyen van a";
    string formatted = cvFileRenamer.rename(original);
    cout << "Original: " << original << endl;
    cout << "Formatted: " << formatted << endl;

    return 0;
}