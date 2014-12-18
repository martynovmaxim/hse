#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main(){
    string s;
    getline(cin, s);
    for (size_t i = 0; i < s.size(); ++i) {
        string t;
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }
        t += s[i];
        while (i < s.size() && s[i] != '.') {
            ++i;
            t += s[i];
        }
        cout << t << endl;
    }
    return 0;
}
