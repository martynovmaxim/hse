#include <iostream>

class Complex {
        double real, image;
    public:
        /*
         * ...
         */
        friend std::ostream& operator << (std::ostream& s, const Complex& z);
        friend std::istream& operator >> (std::istream& s, Complex& z);
};

/*void print_complex(const Complex& z) {
    std::cout << z.real << ' ' << z.image;
}*/

std::ostream& operator << (std::ostream& s, const Complex& z) {
    return s << z.real << ' ' << z.image;
}
std::istream& operator >> (std::istream& s, Complex& z) {
    return s >> z.real >> z.image;
}

int main(void) {
    Complex z;
    operator >> (std::cin, z);
    std::cin >> z;
    (operator << (std::cout, z)).operator << (std::endl);
    std::cout << z << std::endl;
    return 0;
}
