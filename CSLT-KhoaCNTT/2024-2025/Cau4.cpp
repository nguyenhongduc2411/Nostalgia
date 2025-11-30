#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
};

/*

1 -> 2 -> 3 -> 4 -> 5 -> NULL

2 -> 4

2 -> 4 -> 1 -> 5
1 -> 5 -> 2 -> 4

*/

// Hàm chỉ dùng để test
List createList(int *a, int n) {
    List l;
    l.pHead = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node{a[i], nullptr};
        if (!l.pHead) {
            l.pHead = newNode;
            tail = newNode;
        }
        else {
            tail->pNext = newNode;
            tail = newNode;
        }
    }
    return l;
}

// Hàm chỉ dùng để test
void printList(List L) {
    Node* p = L.pHead;
    while (p) {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << "\n";
}

// Hàm chỉ dùng để test
void deleteList(List& L) {
    while (L.pHead) {
        Node* temp = L.pHead;
        L.pHead = L.pHead->pNext;
        delete temp;
    }
}

// 4a
void moveOdd2LeftEven2Right(List& L)
{
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;

    Node* p = L.pHead;
    while (p) {
        // Chẵn
        if (p->data % 2 == 0) {
            if (!evenHead) {
                evenHead = evenTail = p;
            }
            else {
                evenTail->pNext = p;
                evenTail = p;
            }
        }
        // Lẻ
        else {
            if (!oddHead) {
                oddHead = oddTail = p;
            }
            else {
                oddTail->pNext = p;
                oddTail = p;
            }
        }
        p = p->pNext;
    }

    if (evenTail) {
        evenTail->pNext = nullptr;
    }

    if (oddTail) {
        oddTail->pNext = evenHead;
        L.pHead = oddHead;
    }
}

// 4b
void reduceList(List& L, int K)
{
    while (L.pHead && L.pHead->pNext) {
        int cnt = 1;
        Node* p = L.pHead->pNext;
        int sum = L.pHead->data;

        while (p && cnt < K) {
            sum -= p->data;

            Node* temp = p;
            p = p->pNext;
            delete temp;

            cnt++;
        }

        L.pHead->data = abs(sum);
        L.pHead->pNext = p;
    }
}

int main()
{
    {
        int a[] = {1, 2, 3, 4, 5};
        int n = sizeof(a) / sizeof(*a);
        List l = createList(a, n);

        printList(l);
        moveOdd2LeftEven2Right(l);
        printList(l);

        deleteList(l);
        cout << "---------\n";
    }

    {
        int a[] = {1, 2, 3, 6, 5, 8};
        int n = sizeof(a) / sizeof(*a);
        List l = createList(a, n);

        printList(l);
        reduceList(l, 3);
        printList(l);

        deleteList(l);
    }

    return 0;
}