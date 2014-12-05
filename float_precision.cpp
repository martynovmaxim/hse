#include <iostream>

int main(void) {
    float f = 0.0;
    double d = 0.0;
    for (size_t i = 0; i < 1000000000; ++i) {
        f += 0.001;
        d += 0.001;
    }
    std::cout << f << ' ' << d << std::endl;
    return 0;
}
