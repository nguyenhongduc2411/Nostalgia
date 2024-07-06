#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

struct List
{
    Node* head;
};

void trimTail(List &L)
{
    int n = 0;
    int cntSpaces = 0;
    Node* p = L.head;

    while (p != nullptr) {
        if (p->data == ' ')
            cntSpaces++;
        else
            cntSpaces = 0;

        n++;
        p = p->next;
    }

    int start = n - cntSpaces;
    int idx = 0;
    p = L.head;
    Node* prev = nullptr;
    
    while (p != nullptr) {
        if (idx < start) {
            prev = p;
            p = p->next;
            idx++;
            continue;
        }

        Node* temp = p;
        p = p->next;

        if (prev != nullptr)
            prev->next = p;

        if (temp == L.head)
            L.head = p;

        delete temp;
        idx++;
    }
}

// Hàm chỉ dùng để test
Node* createList(string a)
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
void printList(List L)
{
    Node* p = L.head;
    int cnt = 0;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
        cnt++;
    }
    cout << "cnt: " << cnt << "\n";
}

// Hàm chỉ dùng để test
void freeList(List &L)
{
    while (L.head != nullptr) {
        Node* temp = L.head;
        L.head = L.head->next;
        delete temp;
    }
}

int main()
{
    // Node* pHead = createList("A B ");
    Node* pHead = createList("   ");
    List L;
    L.head = pHead;

    printList(L);

    trimTail(L);
    printList(L);

    freeList(L);

    return 0;
}