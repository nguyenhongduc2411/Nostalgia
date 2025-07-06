#include <iostream>

struct Fraction {
    friend struct DivisibleFracCounter;
    Fraction(int num, int den) : m_num(num), m_den(den) {
        std::cout << "Create.\n";
    }
    Fraction(const Fraction& f) : m_num(f.m_num), m_den(f.m_den) {
        std::cout << "Copy.\n";
    }
private:
    int m_num, m_den;
};

template <class T> struct Counter {
    void operator()(const T& num) { m_count += check(num); }

    // Đề xuất đưa thẳng mảng vào
    // Hoặc có thể làm hàm tạo đưa mảng vô luôn
    void operator()(const T nums[], int n) {
        for (int i = 0; i < n; i++) {
            m_count += check(nums[i]);
        }
    }

    int operator()() { return m_count; }
    virtual bool check(const T& num) = 0;
protected:
    int m_count = 0;
};

struct DivisibleFracCounter : public Counter<Fraction> {
    bool check(const Fraction& n) { return n.m_num % n.m_den == 0; }
};

int main() {
    Fraction a[] = { {1, 2}, {3, 3}, {4, 2} };
    int n = sizeof(a) / sizeof(*a);
    DivisibleFracCounter count;
    count(a, n);
    // for (int i = 0; i < n; i++) count(a[i]);
    std::cout << count();
    return 0;
}