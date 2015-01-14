#pragma once

#include <vector>
#include <utility>
#include <cstdlib>

void insertion_sort(std::vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = i; j != 0 && a[j] < a[j - 1]; --j) {
            std::swap(a[j], a[j - 1]);
        }
    }
}
