#include <chrono>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::chrono::steady_clock;

void pr(const vector<vector<double>>& A) {
    for (const vector<double>& row : A) {
        for (double e : row) {
            cout << e << ' ' ;
        }
        cout << std::endl;
    }
    /*for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            cout << A[i][j] << ' ';
        }
        cout << std::endl;
    }*/
} 

int main(void) {
    const size_t N = 800;
    vector<vector<double>> A(N, vector<double>(N));
    vector<vector<double>> B(N, vector<double>(N));
    vector<vector<double>> C(N, vector<double>(N, 0.0));
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            A[i][j] = static_cast<double>(i) + static_cast<double>(j);
            B[i][j] = static_cast<double>(i) - static_cast<double>(j);
        }
    }

    steady_clock::time_point start = steady_clock::now();
    for (size_t i = 0; i < N; ++i) {
        for (size_t k = 0; k < N; ++k) {
            for (size_t j = 0; j < N; ++j) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << std::chrono::duration_cast<std::chrono::duration<double>>(steady_clock::now() - start).count() << std::endl;
    return 0;
}
