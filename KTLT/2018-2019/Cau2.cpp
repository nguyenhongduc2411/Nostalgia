#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// ax^n
struct Node
{
    int a;
    int n;
    Node* next;
};

double tinhGiaTri(Node* head, double x)
{
    if (head == nullptr)
        return 0;

    double sum = 0;

    Node* p = head;
    while (p != nullptr) {
        sum += p->a * pow(x, p->n);
        p = p->next;
    }

    return sum;
}

int main()
{
    vector<vector<int>> a = {
        {2, 0},
        {3, 2},
        {4, 5}
    };

    Node* head = nullptr;
    Node* p = nullptr;

    for (const vector<int>& current : a) {
        Node* newNode = new Node{current[0], current[1]};
        newNode->next = nullptr;

        if (p != nullptr)
            p->next = newNode;
        p = newNode;

        if (head == nullptr)
            head = newNode;
    }

    cout << tinhGiaTri(head, 7);

    return 0;
}