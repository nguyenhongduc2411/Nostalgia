#include <iostream>
using namespace std;

/*

- Attributes:
  - int* arr
  - size
- Methods:
  - PrimeList()
  - PrimeList(int upperBound)
  - ~PrimeList()

  - void generate(int upperBound)
  - int count()
  - bool isPrime(int n)

  - copy assignment operator (operator =)
  - operator <<
  - operator []

*/

class PrimeList
{
private:
    int* arr;
    int size;

    bool isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
public:
    PrimeList() {
        arr = nullptr;
        size = 0;
    }

    PrimeList(int upperBound) {
        arr = nullptr;
        size = 0;
        generate(upperBound);
    }

    ~PrimeList() {
        if (arr != nullptr)
            delete[] arr;

        arr = nullptr;
        size = 0;
    }
    
    void generate(int upperBound) {
        if (arr != nullptr)
            delete[] arr;

        arr = nullptr;
        size = 0;
        for (int i = 2; i < upperBound; i++) {
            if (isPrime(i))
                size++;
        }

        if (size == 0)
            return;

        arr = new int[size];
        int idx = 0;
        for (int i = 2; i < upperBound; i++) {
            if (isPrime(i)) {
                arr[idx] = i;
                idx++;
            }
        }
    }

    int count() {
        return size;
    }

    friend ostream& operator<<(ostream& out, const PrimeList& list) {
        for (int i = 0; i < list.size; i++) {
            out << list[i] << " ";
        }
        out << "\n";
        return out;
    }

    int operator[](int idx) const {
        if (idx < 0 || idx >= size)
            throw std::invalid_argument("idx is invalid");

        return arr[idx];
    }

    PrimeList& operator=(PrimeList& list) {
        if (this == &list)
            return *this;

        if (arr != nullptr)
            delete[] arr;

        arr = nullptr;
        size = list.size;

        if (list.size > 0) {
            arr = new int[size];
            for (int i = 0; i < list.size; i++) {
                arr[i] = list[i];
            }
        }

        return *this;
    }
};

int main()
{
    PrimeList list1(100);
    cout << list1;
    list1.generate(500);

    PrimeList list2;
    list2 = list1;

    cout << "list2.count(): " << list2.count() << "\n";
    cout << list2;

    list1.generate(100);
    cout << "list1.count(): " << list1.count() << "\n";
    cout << list1;

    cout << "list2.count(): " << list2.count() << "\n";
    cout << list2;

    // cout << list2[list2.count() - 1];
}