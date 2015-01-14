#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <map>
#include <algorithm>
#include <initializer_list>
#include <cassert>
#include <iterator>
#include <functional>

#include "insertion_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

using std::vector;
using std::cout;
using std::map;
using std::string;
using std::chrono::steady_clock;

using test_set = map<string, vector<int>>;

unsigned long long int get_random() {
    constexpr unsigned long long int a = 12005053;
    constexpr unsigned long long int b = 123456789;
    constexpr unsigned long long int m = 1000000007;
    static unsigned long long int x = 0;
    x = (a * x + b) % m;
    return x;
}

test_set get_tests(size_t size) {
    test_set result;
    result["sorted"].resize(size);
    std::iota(result["sorted"].begin(), result["sorted"].end(), 0);
    result["reversed"] = result["sorted"];
    std::reverse(result["reversed"].begin(), result["reversed"].end());
    result["random"].resize(size);
    std::generate(result["random"].begin(), result["random"].end(), get_random);
    return result;
}

int main(int, const char *argv[]) {
    map<string, std::function<void(vector<int>&)>> sorts;

    sorts["std"] = [](vector<int>& a) {return std::sort(a.begin(), a.end());};
    sorts["std_stable"] = [](vector<int>& a) {return std::stable_sort(a.begin(), a.end());};
    sorts["insertion"] = insertion_sort;
    sorts["merge"] = merge_sort;
    sorts["heap"] = heap_sort;

    auto sort = sorts[argv[1]];
    auto size = std::stoi(argv[2]);

    for (const auto& test : get_tests(size)) {
        int times = 0;
        double time = 0;
        while (time < .3) {
            ++times;
            auto data = test.second;
            steady_clock::time_point start = steady_clock::now();
            sort(data);
            time += std::chrono::duration_cast<std::chrono::duration<double>>(steady_clock::now() - start).count();
            assert(std::is_sorted(data.begin(), data.end()));
        }
        std::cout << argv[1] << ' ' << test.first << ' ' << size << "; seconds per iteration: " << (time / times) << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
