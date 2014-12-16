#include <iostream>
#include <vector>

class Shape {
    public:
        virtual void draw() = 0;
        virtual ~Shape() {};
};

class Circle: public Shape {
    public:
        double radius;
        virtual void draw() {
            std::cout << "I am a circle\n";
        }
};
class Rectangle: public Shape {
    public:
        double a, b;
        virtual void draw() {
            std::cout << "I am a rectangle\n";
        }
};

void draw_many_shapes(std::vector<Shape *> shapes) {
    for (auto& shape : shapes) {
        shape->draw();
    }
}

int main(void) {
    std::vector<Shape *> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());
    draw_many_shapes(shapes);
    delete shapes[1];
    delete shapes[0];
    return 0;
}
