#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

/*

25->6->25->56->33->25->NULL
19->25->25->NULL

*/

bool removeNodes(Node* &pHead, int data)
{
    bool found = false;
    Node* p = pHead;
    Node* prev = nullptr;
    while (p != nullptr) {
        if (p->data != data) {
            prev = p;
            p = p->next;
            continue;
        }

        Node* temp = p;
        p = p->next;

        if (prev != nullptr)
            prev->next = p;

        if (temp == pHead)
            pHead = p;

        delete temp;
        found = true;
    }
    return found;
}

// Câu a
void removeSameNodes(Node* &pHead1, Node* &pHead2)
{
    Node* p = pHead1;
    while (p != nullptr) {
        bool found = removeNodes(pHead2, p->data);

        if (!found) {
            p = p->next;
            continue;
        }

        removeNodes(pHead1, p->data);
        p = pHead1; // Important!!!
    }
}

// Câu b
void merge(Node* pHead1, Node* pHead2, int* &a, int& n)
{
    if (a != nullptr)
        delete[] a;

    n = 0;

    Node* p = pHead1;
    while (p != nullptr) {
        n++;
        p = p->next;
    }

    p = pHead2;
    while (p != nullptr) {
        n++;
        p = p->next;
    }

    a = new int[n];
    int idx = 0;

    p = pHead1;
    while (p != nullptr) {
        a[idx] = p->data;
        idx++;
        p = p->next;
    }

    p = pHead2;
    while (p != nullptr) {
        a[idx] = p->data;
        idx++;
        p = p->next;
    }

    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Hàm chỉ dùng để test
Node* createList(vector<int> a)
{
    Node* head = nullptr;
    Node* prev = nullptr;

    for (int i = 0; i < a.size(); i++) {
        Node* newNode = new Node{a[i], nullptr};

        if (prev != nullptr)
            prev->next = newNode;

        prev = newNode;

        if (head == nullptr)
            head = newNode;
    }

    return head;
}

// Hàm chỉ dùng để test
void printList(Node* pHead)
{
    Node* p = pHead;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

// Hàm chỉ dùng để test
void freeList(Node* &pHead)
{
    while (pHead != nullptr) {
        Node* temp = pHead;
        pHead = pHead->next;
        delete temp;
    }
}

int main()
{
    Node* pHead1 = createList({25, 6, 6, 6, 56, 33});
    Node* pHead2 = createList({19, 25, 25, 6});

    printList(pHead1);
    printList(pHead2);

    removeSameNodes(pHead1, pHead2);

    cout << "After removeSameNode:\n";
    printList(pHead1);
    printList(pHead2);

    cout << "After merge:\n";
    int *a = nullptr;
    int n = 0;
    merge(pHead1, pHead2, a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    delete[] a;

    freeList(pHead1);
    freeList(pHead2);

    return 0;
}