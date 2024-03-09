#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i < x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int countPrime(Node* h) {
    if (h == nullptr)
        return 0;

    int countCurrent = 0;
    if (isPrime(h->data))
        countCurrent = 1;

    int count = countPrime(h->next);
    return count + countCurrent;
}

int main()
{
    Node* h = nullptr;
    Node* current = nullptr;
    Node* prev = nullptr;

    vector<int> a = {2};
    for (int i = 0; i < a.size(); i++){
        current = new Node;
        current->data = a[i];
        current->next = nullptr;

        if (prev != nullptr)
            prev->next = current;
        prev = current;

        if (h == nullptr)
            h = current;
    }
    cout << countPrime(h);
    return 0;
}