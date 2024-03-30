#include <iostream>
#include <string>
using namespace std;

struct DayNode
{
    int day;
    string date;
    float height;
    float weight;
    DayNode* next;
};

struct MonthNode
{
    int month;
    int year;
    DayNode* head;
    MonthNode* next;
};

struct MyList
{
    MonthNode* head;
};

// Cau b
void printList(MyList& list)
{
    // Lấy ra tháng gần nhất
    MonthNode* p = list.head;

    while (p != nullptr) {
        // Lấy ra ngày gần nhất của tháng
        DayNode* q = p->head;
        if (q != nullptr) {
            cout << q->date << " " << q->height << "m " << q->weight << "kg\n";
        }

        // Đi tới tháng trước đó (Chính là phần tử tiếp theo của dslk)
        p = p->next;
    }
}

struct Date
{
    string date;
    float height;
    float weight;
};

// Cau c
Date* readArray(int& size)
{
    cout << "Nhap so ngay can nhap: ";
    cin >> size;
    Date* dates = new Date[size];

    for (int i = 0; i < size; i++) {
        cout << "Nhap ngay-thang-nam, chieu cao, can nang: ";
        cin >> dates[i].date >> dates[i].height >> dates[i].weight;
    }

    return dates;
}

// Cau d
DayNode* readSimpleList()
{
    DayNode* head = nullptr;
    while (true) {
        cout << "Nhap ngay-thang-nam, chieu cao, can nang (Hoac STOP de ket thuc nhap): ";
        string date;
        cin >> date;

        if (date == "STOP")
            break;

        float height, weight;
        cin >> height >> weight;

        int day = stoi(date.substr(0, 2));
        DayNode* newNode = new DayNode{day, date, height, weight, nullptr};
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main()
{
    // Test cau c
    int size;
    Date* dates = readArray(size);
    for (int i = size - 1; i >= 0; i--) {
        cout << dates[i].date << " " << dates[i].height << "m " << dates[i].weight << "kg\n";
    }

    // Test cau d
    DayNode* head = readSimpleList();
    DayNode* p = head;
    while (p != nullptr) {
        cout << p->date << " " << p->height << "m " << p->weight << "kg\n";
        p = p->next;
    }

    return 0;
}