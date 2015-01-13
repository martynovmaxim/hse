#include <vector>
#include <utility>
#include <cstdlib>

using move = std::pair<size_t, size_t>;

std::vector<move> get_moves(size_t n, size_t from, size_t to) {
    if (n == 1) {
        return {move(from, to)};
    }
    size_t tmp = 3 - from - to;
    auto result = get_moves(n - 1, from, tmp);
    result.emplace_back(from, to);
    auto move_back = get_moves(n - 1, tmp, to);
    result.insert(result.end(), move_back.begin(), move_back.end());
    return result;
}

std::vector<move> get_moves(size_t n) {
    return get_moves(n, 0, 1);
}
