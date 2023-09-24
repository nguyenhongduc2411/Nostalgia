#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*

Ghi lần lượt vào trong tập tin:
- Số lượng đa giác (M)
- Lặp M lần qua từng đa giác
  - Số lượng đỉnh của đa giác hiện tại (n)
  - Lặp n lần qua từng đỉnh
    - Tọa độ x của đỉnh hiện tại
    - Tọa độ y của đỉnh hiện tại

*/

struct Point
{
    int x;
    int y;

    void write(ofstream& out)
    {
        out.write((char*)(&x), sizeof(x));
        out.write((char*)(&y), sizeof(y));
    }

    void read(ifstream& in)
    {
        in.read((char*)(&x), sizeof(x));
        in.read((char*)(&y), sizeof(y));
    }
};

struct Polygon
{
    vector<Point> points;

    void write(ofstream& out)
    {
        size_t n = points.size();
        out.write((char*)(&n), sizeof(n));

        for (Point& point : points) {
            point.write(out);
        }
    }

    void read(ifstream& in)
    {
        size_t n;
        in.read((char*)(&n), sizeof(n));
        points.resize(n);
        
        for (Point& point : points) {
            point.read(in);
        }
    }
};

struct PolygonCollection
{
    vector<Polygon> polygons;

    void write(ofstream& out)
    {
        size_t n = polygons.size();
        out.write((char*)(&n), sizeof(n));
        
        for (Polygon& polygon : polygons) {
            polygon.write(out);
        }
    }

    void read(ifstream& in)
    {
        size_t n;
        in.read((char*)(&n), sizeof(n));
        polygons.resize(n);
        
        for (Polygon& polygon : polygons) {
            polygon.read(in);
        }
    }
};

void write()
{
    ofstream out("DAGIAC.BIN", ios::out | ios::binary);

    PolygonCollection collection;
    collection.polygons = {
        Polygon {
            {
                {1, 2},
                {3, 4},
                {5, 6}
            },
        },
        Polygon {
            {
                {-1, 2},
                {-3, 4},
                {-5, 6},
                {-7, 8}
            }
        }
    };
    collection.write(out);
}

void read()
{
    ifstream in("DAGIAC.BIN", ios::in | ios::binary);
    PolygonCollection collection;
    collection.read(in);

    // Test
    for (int i = 0; i < collection.polygons.size(); i++) {
        Polygon polygon = collection.polygons[i];
        cout << "Da giac " << (i + 1) << ": ";
        for (Point& point : polygon.points) {
            cout << "(" << point.x << ", " << point.y << ") ";
        }
        cout << "\n";
    }
}

int main()
{
    write();  
    read();
    return 0;
}