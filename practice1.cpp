#include <iostream>

using namespace std;

class Rectangle{
    double width, height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    Rectangle() : width(5), height(5) {}

    void setWidth(double newWidth){
        width = newWidth;
    }
    void setHeight(double newHeight){
        height = newHeight;
    }
    double getArea() const{
        return width * height;
    }
    void display(){
        cout << "width: " << width << ", height: " << height << ", area: " << getArea() << '\n';
    }
};

int main(){
    Rectangle rect1, rect2(10,10);
    rect1.setHeight(8);
    rect1.setWidth(8);
    rect2.setHeight(16);
    rect2.setWidth(16);
    rect1.display();
    rect2.display();
    return 0;
}
