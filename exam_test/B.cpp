#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::map;
using std::make_pair;

int main(void) {
    map<char, vector<string>> dict;
    string s;
    while (cin >> s) {
        dict[s[0]].push_back(s);
    }
    for (auto i : dict) {
        std::sort(i.second.begin(), i.second.end());
        std::cout << i.first << ':' << std::endl;
        for (auto k : i.second) {
            std::cout << k << std::endl;
        } 
    }
    return 0;
}
