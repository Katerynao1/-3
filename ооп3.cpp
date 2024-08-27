#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
using namespace std;

class SFigure
{
public:
    SFigure() {}
    virtual double Volume() = 0;  
};

class Cube : public SFigure
{
private:
    double a;
public:
    Cube(double side) : SFigure(), a(side) {}
    double Volume() override {
        return a * a * a;
    }
};

class Sphere : public SFigure
{
private:
    double R;
public:
    Sphere(double radius) : SFigure(), R(radius) {}
    double Volume() override {
        return (4.0 / 3.0) * M_PI * R * R * R;
    }
};

class Cylinder : public SFigure
{
private:
    double r, h;
public:
    Cylinder(double radius, double height) : SFigure(), r(radius), h(height) {}
    double Volume() override {
        return M_PI * r * r * h;
    }
};
class ShapeContainer {
   vector<shared_ptr<SFigure>> shapes;

public:
    // Функція для додавання нових елементів
    void addShape(shared_ptr<SFigure> shape) {
        shapes.push_back(shape);
    }

    // Функція для знаходження фігури з найменшим об'ємом
    shared_ptr<SFigure> findSmallestVolumeShape() const {
        if (shapes.empty()) return nullptr;

        auto smallest = shapes[0];
        for (const auto& shape : shapes) {
            if (shape->Volume() < smallest->Volume()) {
                smallest = shape;
            }
        }
        return smallest;
    }
};

int main() {
    ShapeContainer container;

    double side, radius, height;

    cout << "Enter side length for the cube: ";
    cin >> side;
    shared_ptr<SFigure> cube = make_shared<Cube>(side);
    container.addShape(cube);

    cout << "Enter radius for the sphere: ";
    cin >> radius;
    shared_ptr<SFigure> sphere = make_shared<Sphere>(radius);
    container.addShape(sphere);

    cout << "Enter radius and height for the cylinder: ";
    cin >> radius >> height;
    shared_ptr<SFigure> cylinder = make_shared<Cylinder>(radius, height);
    container.addShape(cylinder);

    cout << "\nShapes volume: " << endl;
    cout << "Cube: " << cube->Volume() << endl;
    cout << "Sphere: " << sphere->Volume() << endl;
    cout << "Cylinder: " << cylinder->Volume() << endl;

    shared_ptr<SFigure> smallestShape = container.findSmallestVolumeShape();
    if (smallestShape) {
        cout << "The smallest volume: " << smallestShape->Volume() << endl;
    }

    return 0;
}