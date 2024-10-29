#include <iostream>
#include <string>
#include <utility>

class Shape {
private:
    int number_of_sides;
    std::string color;
public:
    Shape(const int n): number_of_sides(n){}
    Shape(const std::string& c): color(c){}
    Shape(const int n, const std::string& c): number_of_sides(n), color(c){}
    const std::string& GetColor() const {
        return color;
    }
    virtual double perimetr() const = 0;
    virtual double area() const = 0;
    virtual ~Shape(){}
};

class Ellipse: public Shape {
private:
    int number_of_sides=1;
    double a=0;
    double b=0;
public:
    Ellipse(const double a, const double b): Shape(1), a(a), b(b){}
    Ellipse(const std::string& c): Shape(c){}
    double area() const override {
        return 3.14*a*b;
    }
};

class Circle: public Ellipse {
private:
    int number_of_sides=1;
    double r=0;
public:
    Circle(const double r): Ellipse(r, r){}
    Circle(const std::string& c): Ellipse(c){}
    double perimetr() const override {
        return 3.14*r*2;
    }
    double area() const override {
        return 3.14*r*r;
    }
};

class Tetragon: public Shape {
private:
    int number_of_sides=4;
    double longest_side=0;
public:
    Tetragon(const std::string& c): Shape(c){}
    Tetragon(const double l): Shape(4), longest_side(l){}
};

class Rectangle: public Tetragon {
private:
    int number_of_sides=4;
    double a=0;
    double b=0;
public:
    Rectangle(const double a, const double b): Tetragon(a), a(a), b(b){}
    Rectangle(const std::string& c): Tetragon(c){}
    double perimetr() const override {
        return 2*(a+b);
    }
    double area() const override {
        return a*b;
    }
};

class Square: public Rectangle {
private:
    int number_of_sides=4;
    double a=0;
public:
    Square(const double a): Rectangle(a, a), a(a){}
    Square(const std::string& c): Rectangle(c){}
    double perimetr() const override {
        return 4*a;
    }
    double area() const override {
        return a*a;
    }
};
int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
