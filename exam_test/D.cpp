#include <string>
#include <iostream>

class Animal {
    protected:
        std::string name;
    public:
        Animal(const std::string& name): name(name) {}
        virtual void Say() = 0;
};

class Dog: public Animal {
    public:
        Dog(const std::string& name): Animal(name) {}
        virtual void Say() {
            std::cout << "Woof, " << name << '!' << std::endl;
        }
};
class Cat: public Animal {
    public:
        Cat(const std::string& name): Animal(name) {}
        virtual void Say() {
            std::cout << "Meow, " << name << '!' << std::endl;
        }
};
