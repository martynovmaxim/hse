#include <map>
#include <iostream>

int main() {
    std::map<int, int> a;
    a[1] = 2;
    a[5] = a[1];
    a[100500] = 42;
    for (std::map<int, int>::iterator i = a.begin(); i != a.end(); ++i) {
        std::cout << i->first << ' ' << i->second << std::endl;
    }
    return 0;
}
