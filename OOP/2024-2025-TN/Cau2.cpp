#include <iostream>

class Fraction
{
private:
    int m_num, m_den;
public:
    Fraction(int num, int den) : m_num(num), m_den(den) {}
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.m_num << "/" << f.m_den;
        return os;
    }

    int num() {
        return m_num;
    }

    int den() {
        return m_den;
    }
};

class PrimeFracIterator
{
private:
    Fraction* a;
    int n;
    int idx;

    bool isPrime(int x) {
        if (x < 2)
            return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    void goToNextPrime() {
        while (idx < n && (!isPrime(a[idx].num()) || !isPrime(a[idx].den()))) {
            idx++;
        }
    }

public:
    PrimeFracIterator(Fraction a[], int n) : a(a), n(n), idx(0) {
        goToNextPrime();
    }

    operator bool() {
        return 0 <= idx && idx < n;
    }

    Fraction& operator*() {
        return a[idx];
    }

    PrimeFracIterator& operator++() {
        ++idx;
        goToNextPrime();
        return *this;
    }
};

int main()
{
    Fraction a[] = {{1, 2}, {2, 3}, {4, 2}, {3, 5}};
    int n = sizeof(a) / sizeof(*a);

    PrimeFracIterator i(a, n);
    while (i) {
        std::cout << *i << " ";
        ++i;
    }

    return 0;
}