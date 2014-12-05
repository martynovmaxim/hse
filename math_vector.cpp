#include <vector>
#include <iostream>

template<class T, size_t N> class MathVector {
    private:
        std::vector<T> coord;
    public:
        MathVector(): coord(N, 0) {
        }
        const MathVector<T, N>& operator +=(const MathVector<T, N>& other) {
            for (int i = 0; i < N; ++i) {
                coord[i] += other.coord[i];
            }
            return *this;
        }
        MathVector<T, N> operator +(const MathVector<T, N>& other) const {
            MathVector<T, N> result(*this);
            result += other;
            return result;
        }
        T operator *(const MathVector<T, N>& other) const {
            T result = 0;
            for (int i = 0; i < N; ++i) {
                result += coord[i] * other[i];
            }
            return result;
        }
        T& operator [](const size_t i) {
            return coord[i];
        }
        const T& operator [](const size_t i) const {
            return coord[i];
        }
        template<size_t N1> MathVector<T, N + N1> concatenate(const MathVector<T, N1>& other) const {
            MathVector<T, N + N1> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = (*this)[i];
            }
            for (size_t i = N; i < N + N1; ++i) {
                result[i] = other[i - N];
            }
            return result;
        }
};

int main(void) {
    MathVector<int, 2> a;
    MathVector<int, 3> b;
    auto c = a.concatenate(b);
    /*MathVector<int, 2> a, b, c;
    a[0] = 1;
    a[1] = 2;
    b[0] = 3;
    b[1] = 4;
    c = a + b;
    std::cout << c[0] << ' ' << c[1] << std::endl;*/
    return 0;
}
