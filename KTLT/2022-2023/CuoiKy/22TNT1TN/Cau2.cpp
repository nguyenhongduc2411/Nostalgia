#include <iostream>
#include <vector>
using namespace std;

/*

1 3 5 3 1
1 3 1 3 5

*/

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
};

Node* reverse(Node* head)
{
    Node* p = head;
    Node* prev = nullptr;

    while (p != nullptr) {
        Node* temp = p->next;
        p->next = prev;
        prev = p;
        p = temp;
    }

    return prev;
}

bool isSymmetric(List &L)
{
    if (L.head == nullptr)
        return false;

    Node* p = L.head;
    Node* prev = nullptr;
    Node* head = nullptr;

    while (p != nullptr) {
        Node* newNode = new Node;
        newNode->data = p->data;
        newNode->next = nullptr;

        if (prev != nullptr)
            prev->next = newNode;

        if (head == nullptr)
            head = newNode;

        prev = newNode;
        p = p->next;
    }

    head = reverse(head);

    p = L.head;
    Node* q = head;

    while (p != nullptr && q != nullptr) {
        if (p->data != q->data)
            return false;

        p = p->next;
        q = q->next;
    }

    return true;
}

bool isSymmetric2(List &L)
{
    if (L.head == nullptr)
        return false;

    Node* slow = L.head;
    Node* fast = L.head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* head2 = reverse(slow);
    
    Node* p = L.head;
    Node* q = head2;

    bool isValid = true;
    while (p != nullptr && q != nullptr) {
        cout << "Compare: " << p->data << " " << q->data << "\n";
        if (p->data != q->data) {
            isValid = false;
            break;
        }

        p = p->next;
        q = q->next;
    }

    reverse(head2);

    return isValid;
}

int main()
{
    vector<int> a = {1, 3, 3, 5};

    List L;

    Node* prev = nullptr;
    Node* head = nullptr;

    for (const int& current : a) {
        Node* newNode = new Node;
        newNode->data = current;
        newNode->next = nullptr;

        if (prev != nullptr)
            prev->next = newNode;

        if (head == nullptr)
            head = newNode;

        prev = newNode;
    }

    L.head = head;
    cout << isSymmetric2(L) << "\n";

    Node* p = L.head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }

    return 0;
}