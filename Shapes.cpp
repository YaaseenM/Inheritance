#include "Shapes.h"
#define PI 3.14159f
#include <string>
#include <iostream>
using std::string;
using namespace std;

Shape :: ~Shape() {

}


void Shape2D::ShowArea() const {
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

bool Shape2D:: operator>(const Shape2D &rhs) const {
    if(Area() > rhs.Area()) {
        return true;
    } else {
        return false;
    }
}

bool Shape2D:: operator<(const Shape2D &rhs) const {
    if(Area() < rhs.Area()) {
        return true;
    } else {
        return false;
    }
}

bool Shape2D:: operator==(const Shape2D &rhs) const {
    if(Area() == rhs.Area()) {
        return true;
    } else {
        return false;
    }
}

void Square::Scale(float scaleFactor) {
    this->var1 = var1 * scaleFactor;
    this->area = var1 * var1;
}

void Square::Display() const{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
    cout << "Length of a side: " << var1 << endl;
}

string Square::GetName2D() const{
    return this->name;
}

float Square::Area() const {
    return this->area;

}

Square::Square() {
    this->name = "Square";
    this->var1 = 0.00f;
    this->area = var1 * var1;
}

Square::Square(float l) {
    this->name = "Square";
    this->var1 = l;
    this->area = var1 * var1;
}

void Triangle::Scale(float scaleFactor) {
    this->var1 = var1 * scaleFactor;
    this->var2 = var2 * scaleFactor;
    this->area = var1 * var2 * (0.5);
}

void Triangle::Display() const{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
    cout << "Base: " << var1 << endl;
    cout << "Height: " << var2 << endl;
}

string Triangle::GetName2D() const{
    return this->name;
}

float Triangle::Area() const {
    return (var1 * var2 * 0.5);

}

Triangle::Triangle() {
    this->name = "Triangle";
    this->var1 = 0.00f;
    this->var2 = 0.00f;
    this->area = var1 * var2 * (0.5);
}

Triangle::Triangle(float b, float h) {
    this->name = "Triangle";
    this->var1 = b;
    this->var2 = h;
    this->area = var1 * var2 * (0.5);
}

void Circle::Scale(float scaleFactor) {
    this->cVar1 = cVar1 * scaleFactor;
    this->area = cVar1 * cVar1 * PI;
}

void Circle::Display() const{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
    cout << "Radius: " << cVar1 << endl;
}

string Circle::GetName2D() const{
    return this->name;
}

float Circle::Area() const {
    return (cVar1 * cVar1 * PI);
}

Circle::Circle() {
    this->name = "Circle";
    this->cVar1 = 0.00f;
    this->area = cVar1 * cVar1 * PI;
}

Circle::Circle(float r) {
    this->name = "Circle";
    this->cVar1 = r;
    this->area = cVar1 * cVar1 * PI;
}

void Shape3D::ShowVolume() const {
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D:: operator>(const Shape3D &rhs) const {
    if(Volume() > rhs.Volume()) {
        return true;
    } else {
        return false;
    }
}

bool Shape3D:: operator<(const Shape3D &rhs) const {
    if(Volume() < rhs.Volume()) {
        return true;
    } else {
        return false;
    }
}

bool Shape3D:: operator==(const Shape3D &rhs) const {
    if(Volume() == rhs.Volume()) {
        return true;
    } else {
        return false;
    }
}

void TriangularPyramid::Scale(float scaleFactor) {
    Triangle::var1 = Triangle::var1 * scaleFactor;
    Triangle::var2 = Triangle::var2 * scaleFactor;
    this->var3 = var3 * scaleFactor;
    this->volume = Triangle::Area() * var3 * TriangularPyramid::mVar * 0.5;
}

void TriangularPyramid::Display() const{
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
    cout << "The height is: " << var3 << endl;
    cout << "The area of the "<< Triangle::GetName2D()  << " is : " << Triangle::Area() << endl;
    cout << "Base: " << Triangle::var1 << endl;
    cout << "Height: " << Triangle::var2 << endl;
}

string TriangularPyramid::GetName3D() const{
    return this->name;
}

float TriangularPyramid::Volume() const {
    return this->volume;

}

TriangularPyramid::TriangularPyramid() {
    this->name = "TriangularPyramid";
    Triangle::var1 = 0.00f;
    Triangle::var2 = 0.00f;
    this->var3 = 0.00f;
    this->volume = Triangle::var1 * Triangle::var2 * var3 * TriangularPyramid::mVar;
}

TriangularPyramid::TriangularPyramid(float b, float h1, float h2) {
    this->name = "TriangularPyramid";
    Triangle::var1 = h1;
    Triangle::var2 = h2;
    this->var3 = b;
    this->volume = Triangle::var1 * Triangle::var2 * var3 * mVar * 0.5;
}

void Cylinder::Scale(float scaleFactor) {
    Circle::cVar1 = Circle::cVar1 * scaleFactor;
    this->var2 = var2 * scaleFactor;
    this->volume = Circle::Area() * var2;
}

void Cylinder::Display() const{
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
    cout << "The height is: " << var2 << endl;
    cout << "The area of the " << Circle::GetName2D() << " is : " << Circle::Area() << endl;
    cout << "Radius: " << Circle::cVar1 << endl;
}

string Cylinder::GetName3D() const{
    return this->name;
}

float Cylinder::Volume() const {
    return this->volume;
}

Cylinder::Cylinder() {
    this->name = "Cylinder";
    Circle::cVar1 = 0.00f;
    this->var2 = 0.00f;
    this->volume = Circle::Area() * var2;
}

Cylinder::Cylinder(float h, float r) {
    this->name = "Cylinder";
    this->var2 = h;
    Circle::cVar1 = r;
    this->volume = Circle::Area() * var2;
}

void Sphere::Scale(float scaleFactor) {
    Circle::cVar1 = Circle::cVar1 * scaleFactor;
    this->volume = Circle::Area() * Circle::cVar1 * Sphere::mVar;
}

void Sphere::Display() const{
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
    cout << "The area of the " << Circle::GetName2D() << " is : " << Circle::Area() << endl;
    cout << "Radius: " << Circle::cVar1 << endl;
}

string Sphere::GetName3D() const{
    return this->name;
}

float Sphere::Volume() const {
    return this->volume;

}

Sphere::Sphere() {
    this->name = "Sphere";
    Circle::cVar1 = 0.00f;
    this->volume = Circle::cVar1 * Circle::Area() * Sphere::mVar;
}

Sphere::Sphere(float r) {
    this->name = "Sphere";
    Circle::cVar1 = r;
    this->volume = Circle::cVar1 * Circle::Area() * Sphere::mVar;
}