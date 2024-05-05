#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

Node* reverse(Node* head)
{
    if (head == nullptr)
        return nullptr;

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

bool isPalindrome(Node* head)
{
    if (head == nullptr)
        return true;

    Node* fast = head;
    Node* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* head2 = reverse(slow);

    Node* p = head;
    Node* q = head2;

    bool valid = true;
    while (p != nullptr && q != nullptr) {
        if (p->data != q->data) {
            valid = false;
        }
        p = p->next;
        q = q->next;
    }

    reverse(head2);

    return valid;
}

int main()
{
    const char* s = "";
    int size = strlen(s);

    Node* head = nullptr;
    Node* p = nullptr;
    for (int i = 0; i < size; i++) {
        Node* newNode = new Node{s[i], nullptr};

        if (p != nullptr)
            p->next = newNode;

        p = newNode;

        if (head == nullptr)
            head = newNode;
    }

    cout << isPalindrome(head) << "\n";

    return 0;
}