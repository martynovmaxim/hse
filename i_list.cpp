#include <iostream>
#include <utility>

struct A {
    A(std::initializer_list<int> l) {
        std::cout << "l.size(): " << l.size() << std::endl;
        for (auto i = l.begin(); i != l.end(); ++i) {
            std::cout << *i << std::endl;
        }
    }
};

int main() {
    A a {5, 7, 42};
    return 0;
}
