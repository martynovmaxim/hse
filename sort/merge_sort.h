#pragma once

#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;

void merge(vector<int>& a, vector<int>&b, size_t left, size_t middle, size_t right) {
    for (size_t i = left, j0 = left, j1 = middle; i < right; ++i) {
        if (j0 < middle && (j1 == right || a[j0] < a[j1])) {
            b[i] = a[j0];
            ++j0;
        }
        else {
            b[i] = a[j1];
            ++j1;
        }
    }
}

void split(vector<int>& a, vector<int>& b, size_t left, size_t right) {
    if (right - left < 2) {
        return;
    }
    size_t middle = (left + right) / 2;
    split(a, b, left, middle);
    split(a, b, middle, right);
    merge(a, b, left, middle, right);
    std::copy(b.begin() + left, b.begin() + right, a.begin() + left);
}

void merge_sort(vector<int>& a) {
    vector<int> b(a.size());
    return split(a, b, 0, a.size());
}
