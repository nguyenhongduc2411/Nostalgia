#include <iostream>
using namespace std;

class Figure {
protected:
    string _name;
public:
    virtual void showFigure() {
        cout << _name << endl;
    }
    virtual double calcArea() = 0;
    // Figure() {
    //     cout << "Figure constructor" << endl;
    // }
    // ~Figure() {
    //     cout << "Figure destructor" << endl;
    // }
};

class Point {
private:
    int _x, _y;
public:
    Point(int x, int y) {
        cout << "1st point constructor" << endl;
        _x = x;
        _y = y;
    }
    Point(const Point& I) {
        cout << "2nd point constructor" << endl;
        _x = I._x;
        _y = I._y;
    }
    void setX(int x) { _x = x; }
    void setY(int y) { _y = y; }
    int getX() { return _x; }
    int getY() { return _y; }
    ~Point() {
        cout << "Point destructor" << endl;
    }
};

class Circle : public Figure {
private:
    Point* _I; double _R;
public:
    void setI(const Point& I) {
        if (_I == nullptr) _I = new Point(I);
        else *(_I) = I;
    }
    void setR(double R) {
        if (R >= 0) _R = R;
    }
    double getR() { return _R; }
    double calcArea() { return 3.14 * _R * _R; }
    Circle () {
        cout << "Circle constructor" << endl;
        _name = "Circle";
        _I = nullptr;
        _R = 0;
    }
    ~Circle() {
        if (_I != nullptr) delete _I;
        cout << "Circle destructor" << endl;
    }
    void showFigure() {
        cout << _name << ": " << calcArea() << endl;
    };
};

int main()
{
    Circle* c = new Circle();
    Point I(1, 2);
    c->setI(I); c->setR(2);
    c->showFigure();
    delete c;
}