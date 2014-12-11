#include <vector>
#include <iostream>

using std::vector;

class A {
    private:
        vector<int> v;
    public:
        A(const vector<int>& v): v(v) {
        }
        vector<int>::iterator begin() {
            return v.begin();
        }
        vector<int>::iterator end() {
            return v.end();
        }
};

int main(void) {
    A a(vector<int>({5,10,42}));
    for (auto i = a.begin(); i != a.end(); ++i) {
        std::cout << *i << std::endl;
    }
    return 0;
}
