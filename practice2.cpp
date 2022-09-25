#include<iostream>
#include<cmath>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

static const long double pi = acos(-1);

class Circle {
    int radius;
public:
    void set_radius(int new_radius){
        radius = new_radius;
    }
    int get_radius(){
        return radius;
    }
    long double get_area(){
        return pi*radius*radius;
    }
    int get_diameter(){
        return radius*2;
    }
    long double get_circumference(){
        return pi*get_diameter();
    }
};

int main() {
    Circle circle;
    circle.set_radius(5);
    cout.precision(10);
    cout << fixed;
    cout << circle.get_radius() << '\n';
    cout << circle.get_area() << '\n';
    cout << circle.get_diameter() << '\n';
    cout << circle.get_circumference() << '\n';
    return 0;
}