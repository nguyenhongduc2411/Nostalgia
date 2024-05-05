#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

char* toString(Node* head)
{
    int size = 0;
    Node* p = head;
    while (p != nullptr) {
        p = p->next;
        size++;
    }

    char* str = new char[size + 1];
    str[size] = '\0';

    p = head;
    int i = 0;
    while (p != nullptr) {
        str[i] = p->data;
        i++;
        p = p->next;
    }

    return str;
}

int main()
{
    const char* s = "sdfsd ;fksd;l fksd;lfklk";
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

    char* str = toString(head);

    cout << strlen(str) << " " << size << "\n";
    cout << str << "\n";

    return 0;
}