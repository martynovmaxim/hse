#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <array>
#include <iterator>
#include <exception>
#include <cassert>
#include <utility>

using Tower = std::vector<int>;

class TowerSystem {
    private:
        std::array<Tower, 3> towers;
    public:
        TowerSystem(size_t n) {
            towers[0].resize(n);
            std::iota(towers[0].begin(), towers[0].end(), 0);
        }
        friend std::ostream& operator << (std::ostream& os, const TowerSystem& towers) {
            for (const auto& tower : towers.towers) {
                std::cout << '[';
                std::copy(tower.begin(), tower.end(), std::ostream_iterator<int>(std::cout, ", "));
                std::cout << "] ";
            }
            return os;
        }
        void move(size_t from, size_t to) {
            assert(from < 3);
            assert(to < 3);
            assert(!towers[from].empty());
            assert(towers[to].empty() || towers[from].back() > towers[to].back());
            towers[to].push_back(towers[from].back());
            towers[from].pop_back();
            //std::cout << (*this) << std::endl;
        }
};

using move = std::pair<size_t, size_t>;

std::vector<move> get_moves(size_t n);

//#include "my_solution.cpp"

std::vector<move> get_moves(size_t a, size_t b, size_t n) {
    if (n == 0) {
        return std::vector<move> ();
    }
    auto c = 3 - a - b;
    std::vector<move> result = get_moves(a, c, n-1);
    result.push_back(move(a, b));
    for( auto& i:get_moves(c, b, n-1)) {
        result.push_back(i);
    }
    return result;
}

std::vector<move> get_moves(size_t n) {
    return get_moves(0, 1, n);
}
int main(int argc, char *argv[]) {
    assert(argc == 2);
    size_t n = std::stoi(argv[1]);
    TowerSystem towers(n);
    for (const auto& m : get_moves(n)) {
        std::cout << towers << std::endl;
        towers.move(m.first, m.second);
    }
    std::cout << towers << std::endl;
    return 0;
    argc = 0;
}
