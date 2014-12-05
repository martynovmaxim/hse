#include <iostream>

class TRange {
    private:
        int first, last, step;
    public:
        TRange(int last): first(0), last(last), step(1) {
        }
        TRange(int first, int last, int step = 1): first(first), last(last), step(step) {
        }

        struct TIterator {
            int value, step;
            TIterator(int value, int step = 1): value(value), step(step) {
            }
            int operator *() const {
                return value;
            }
            TIterator& operator ++() {
                value += step;
                return *this;
            }
            bool operator != (const TIterator &other) const {
                return value != other.value;
            }
        };

        TIterator begin() const {
            return TIterator(first, step);
        }
        TIterator end() const {
            return TIterator(last, step);
        }
};

int main(void) {
    TRange r(5);
    TRange r2(2, 6);
    TRange r3(3, -7, -2);
    for (TRange::TIterator i = r3.begin(); i != r3.end(); ++i) {
        std::cout << *i << std::endl;
    }
    return 0;
}
