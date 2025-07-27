#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int value, weight;
    Node *pNext;
};

struct List
{
    Node *pHead;
};

void mergeList(List& l1, List& l2)
{
    // Dummy node
    Node* dummy = new Node{0, 0, nullptr}; // Gán nullptr cho dummy->pNext để an toàn trong trường hợp l1 và l2 đều rỗng
    Node* cur = dummy;
    Node* p = l1.pHead;
    Node* q = l2.pHead;
    while (p != nullptr && q != nullptr) {
        if (p->value < q->value) {
            cur->pNext = p;
            p = p->pNext;
        }
        else if (p->value > q->value) {
            cur->pNext = q;
            q = q->pNext;
        }
        else {
            cur->pNext = p;
            p->weight += q->weight;
            Node* temp = q;
            p = p->pNext;
            q = q->pNext;
            delete temp; // Bắt buộc để không bị memory leak
        }
        cur = cur->pNext;
    }
    if (p != nullptr) {
        cur->pNext = p;
    }
    if (q != nullptr) {
        cur->pNext = q;
    }
    l1.pHead = dummy->pNext;
    l2.pHead = nullptr; // Về bản chất thì các node của l2 đã được merge vào l1 hoặc là bị xóa đi -> l2 này không còn giá trị nữa
    delete dummy;
}

Node* createList(vector<vector<int>> a)
{
    Node* head = nullptr;
    Node* prev = nullptr;
    for (vector<int>& element : a) {
        Node* node = new Node{element[0], element[1], nullptr};

        if (head == nullptr)
            head = node;

        if (prev != nullptr)
            prev->pNext = node;

        prev = node;
    }
    return head;
}

void printList(List l)
{
    Node* p = l.pHead;
    while (p != nullptr) {
        cout << "(" << p->value << ", " << p->weight << ") ";
        p = p->pNext;
    }
    cout << "\n";
}

void deleteList(List& l)
{
    while (l.pHead != nullptr) {
        Node* temp = l.pHead;
        l.pHead = temp->pNext;
        delete temp;
    }
}

int main()
{
    List l1, l2;
    l1.pHead = createList({{1, 4}, {2, 2}, {4, 3}, {7, 5}});
    l2.pHead = createList({{1, 3}, {2, 7}, {4, 1}, {7, 4}});

    printList(l1);
    printList(l2);

    mergeList(l1, l2);

    printList(l1);
    printList(l2);

    deleteList(l1);
    deleteList(l2);

    return 0;
}