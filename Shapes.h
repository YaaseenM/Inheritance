#ifndef LAB6_SHAPES_H
#define LAB6_SHAPES_H
#define PI 3.14159f
#include <string>
using std::string;
using namespace std;

class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape();
};

class Shape2D : virtual public Shape
{
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};

class Square : virtual public Shape2D {
    float var1;
    float area ;
    string name;
    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;

public:
    Square();
    Square(float l);
};

class Triangle : virtual public Shape2D {
    float area ;
    string name;
    void Scale(float scaleFactor);
    void Display() const;

protected:
    float Area() const;
    string GetName2D() const;
    float var1;
    float var2;
public:
    Triangle();
    Triangle(float b, float h);
};

class Circle : virtual public Shape2D {
    float area ;
    string name;
    void Scale(float scaleFactor);
    void Display() const;

protected:
    string GetName2D() const;
    float Area() const;
    float cVar1;
public:
    Circle();
    Circle(float l);
};

class Shape3D : virtual public Shape
{
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};

class TriangularPyramid : virtual public Shape3D, private Triangle {
    float var1;
    float var2;
    float var3;
    float mVar = 0.33333333f;
    float volume;
    string name;
    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
public:
    TriangularPyramid();
    TriangularPyramid(float b, float h1, float h2);
};

class Cylinder : virtual public Shape3D, private Circle {
    float var1;
    float var2;
    float volume ;
    string name;
    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
public:
    Cylinder();
    Cylinder(float r, float h);
};


class Sphere : virtual public Shape3D, private Circle {
    float var1;
    float mVar = 1.33333333333f;
    float volume;
    string name;
    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
public:
    Sphere();
    Sphere(float l);
};

#endif