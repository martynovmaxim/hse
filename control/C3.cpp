#include <iostream>
#include <string>

int strspn(const char * str1, const char * str2) {
    int count = 0;
    for (int i = 0; str1[i] != 0; ++i) {
        bool found = false;
        for (int j = 0; str2[j] != 0; ++j) {
            if (str1[i] == str2[j]) {
                ++count;
                found = true;
                break;
            }
        }
        if (!found) {
            break;
        }
    }
    return count;
}

int main(void) {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << strspn(a.c_str(), b.c_str()) << std::endl;
    return 0;
}
