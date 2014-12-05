#include <iostream>
#include <vector>

using std::vector;

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int k = 0;
    for (int i = 0; i < a.size(); ++i) {
        while (k < b.size() && b[k] <= a[i]){
            c.push_back(b[k]);
            ++k;
        }
        c.push_back(a[i]);
    }
    for (; k < b.size(); ++k) {
        c.push_back(b[k]);
    }
    return c;
}

int main() {
    int m, n;
    std::cin >> m;
    vector<int> a(m);
    for (int& i : a) {
        std::cin >> i;
    }
    std::cin >> n;
    vector<int> b(n);
    for (int& i : b) {
        std::cin >> i;
    }
    for (int i : merge(a, b)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}
