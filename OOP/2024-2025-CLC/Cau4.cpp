#include <iostream>
#include <vector>
using namespace std;

enum DrawType
{
    Solid,
    Hollow
};

class IShape
{
protected:
    DrawType _drawType;
    char _character;
public:
    IShape() {
        // Default
        _drawType = Solid;
        _character = '*';
    }

    virtual string toString() const = 0;
    void setDrawType(DrawType drawType) {
        _drawType = drawType;
    }
    void setCharacter(char character) {
        _character = character;
    }
};

class Rectangle : public IShape
{
private:
    int _width;
    int _height;
public:
    Rectangle(int width, int height) {
        if (width < 0)
            throw std::invalid_argument("width must be >= 0");
        
        if (height < 0)
            throw std::invalid_argument("height must be >= 0");
    
        _width = width;
        _height = height;
    }

    // Bắt buộc có thêm từ khóa const để biên dịch được theo code trong đề bài
    // string toString() const override {
    //     return "Rectangle Width=" + to_string(_width) + ", Height=" + to_string(_height);
    // }

    string toString() const override {
        string s;
        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++) {
                switch (_drawType) {
                    case Solid:
                        s += _character;
                        break;
                    case Hollow:
                        if (i == 0 || j == 0 || i == _height - 1 || j == _width - 1)
                            s += _character;
                        else
                            s += ' ';
                        break;
                }
            }
            s += '\n';
        }
        return s;
    }
};

class Square : public IShape
{
private:
    int _side;
public:
    Square(int side) {
         if (side < 0)
            throw std::invalid_argument("side must be >= 0");

        _side = side;
    }

    // Bắt buộc có thêm từ khóa const để biên dịch được theo code trong đề bài
    // string toString() const override {
    //     return "Square Side=" + to_string(_side);
    // }

    string toString() const override {
        string s;
        for (int i = 0; i < _side; i++) {
            for (int j = 0; j < _side; j++) {
                switch (_drawType) {
                    case Solid:
                        s += _character;
                        break;
                    case Hollow:
                        if (i == 0 || j == 0 || i == _side - 1 || j == _side - 1)
                            s += _character;
                        else
                            s += ' ';
                        break;
                }
            }
            s += '\n';
        }
        return s;
    }
};

int main() {
    vector<IShape*> shapes = {
        new Rectangle(10, 6),
        new Square(5),
        new Rectangle(8, 5),
        new Square(3)
    };

    shapes[0]->setCharacter('*');
    shapes[0]->setDrawType(DrawType::Solid);

    shapes[1]->setCharacter('+');
    shapes[1]->setDrawType(DrawType::Hollow);

    shapes[2]->setCharacter('@');
    shapes[2]->setDrawType(DrawType::Solid);

    shapes[3]->setCharacter('-');
    shapes[3]->setDrawType(DrawType::Hollow);

    for (const IShape* shape : shapes) {
        cout << shape->toString() << '\n';
    }

    for (IShape* shape : shapes) {
        delete shape;
    }

    return 0;
}