#include<iostream>

using namespace std;

class Vector2D {
    int x, y;
public:
    Vector2D(int x, int y) : x(x), y(y) {}

    int getX() { return x; }

    int getY() { return y; }

    void setX(int newX) {
        x = newX;
    }

    void setY(int newY) {
        y = newY;
    }

    int operator*(const Vector2D& other) const{
        return x * other.x + y * other.y;
    }
};

int main() {
    Vector2D A(2,2);
    Vector2D B(3,3);
    cout << A*B;
    return 0;
}