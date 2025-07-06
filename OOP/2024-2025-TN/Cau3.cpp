#include <iostream>
#include <vector>

template<class T>
class Filter
{
public:
    virtual void prepare(const std::vector<T>&) {}
    virtual bool check(const T& element, int idx) = 0;
    virtual ~Filter() = default;
};

class DivisibleFilter : public Filter<int>
{
private:
    int N;
public:
    DivisibleFilter(int N) : N(N) {}
    bool check(const int& element, int) override {
        return element % N == 0;
    }
};

template<class T>
class OddIndexFilter : public Filter<T>
{
public:
    bool check(const int&, int idx) override {
        return idx % 2 != 0;
    }
};

template<class T>
class DiffAvgFilter : public Filter<T>
{
private:
    double threshold;
    double avg;
public:
    DiffAvgFilter(double threshold) : threshold(threshold) {}

    void prepare(const std::vector<T>& arr) override {
        double sum = 0;
        for (const T& x : arr) {
            sum += x;
        }
        avg = sum / arr.size();
    }

    bool check(const int& element, int) override {
        double diff = abs(element - avg);
        double rel = diff / abs(avg);
        return rel <= threshold;
    }
};

template<class T>
class Extractor
{
private:
    std::vector<Filter<T>*> filters;
public:
    void add(Filter<T>* filter) {
        filters.push_back(filter);
    }

    std::vector<T> extract(const std::vector<T>& arr) {
        for (Filter<T>* f : filters) {
            f->prepare(arr);
        }

        std::vector<T> result;

        for (size_t i = 0; i < arr.size(); i++) {
            bool good = true;
            for (Filter<T>* f : filters) {
                if (!f->check(arr[i], i)) {
                    good = false;
                    break;
                }
            }
            if (good) {
                result.push_back(arr[i]);
            }
        }

        return result;
    }

    ~Extractor() {
        for (Filter<T>* f : filters) {
            delete f;
        }
    }
};

int main() {
    Extractor<int> ex;
    ex.add(new DivisibleFilter(3));
    ex.add(new OddIndexFilter<int>());
    ex.add(new DiffAvgFilter<int>(0.2));
    std::vector<int> a = {10, 3, 15, 6, 2, 9, 4, 15, 5, 6};
    std::vector<int> b = ex.extract(a);
    for (auto& e : b) {
        std::cout << e << " ";
    }
    return 0;
}
