#include <iostream>
using namespace std;

class Complex
{
private:
    double _real;
    double _imag;
public:
    Complex() {
        _real = 0;
        _imag = 0;
    }

    Complex(double real, double imag) {
        _real = real;
        _imag = imag;
    }
    // Complex(double real, double imag) : _real(real), _imag(imag) {}

    // Operator overloading
    Complex operator+(const Complex& other) {
        return Complex(_real + other._real, _imag + other._imag);
    }
    Complex operator-(const Complex& other) {
        return Complex(_real - other._real, _imag - other._imag);
    }
    Complex operator*(const Complex& other) {
        return Complex(_real * other._real - _imag * other._imag, _real * other._imag + _imag * other._real);
    }

    // Stream operator overloading
    friend istream& operator>>(istream& in, Complex& c) {
        in >> c._real >> c._imag;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c._real << " + " << c._imag << "i";
        return out;    
    }
};

int main()
{
    // Complex a(2, 5);
    // Complex b(4, -3);

    Complex a, b;
    cin >> a;
    cin >> b;

    cout << a << endl; 
    cout << b << endl;

    cout << a * b << endl; 

    return 0;
}