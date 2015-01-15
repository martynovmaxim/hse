#pragma once

#include <vector>
#include <cstdlib>
#include <algorithm>

void heap_sort(std::vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = i; j > 0 && a[j] > a[(j - 1) / 2]; j = (j - 1) / 2) {
            std::swap(a[j], a[(j - 1) / 2]);
        }
    }
    for (size_t i = a.size(); i > 0; --i) {
        std::swap(a[0], a[i - 1]);
        size_t j = 0;
        while (true) {
            size_t left = 2 * j + 1, right = 2 * j + 2;
            if ((right < i - 1) && a[right] > a[left] && a[right] > a[j]) {
                std::swap(a[j], a[right]);
                j = right;
            }
            else {
                if ((left < i - 1) && a[left] > a[j]) {
                    std::swap(a[j], a[left]);
                    j = left;
                }
                else {
                    break;
                }
            }
        }
    }
}
