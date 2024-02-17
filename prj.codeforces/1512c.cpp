#include <iostream>
#include <string>
#include <vector>
 
int main() {
    int t = 0;
    std::cin >> t;
    std::vector<std::string> st;
    while (t--) {
        int zer = 0, one = 0, p = 0;
        p = 1;
        std::string s;
        std::cin >> zer >> one >> s;
        int n = 0;
        n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == s[n - i - 1] && s[i] != '?') {
                if (s[i] == '0') {
                    zer-= 1;
                }
                else {
                    one -= 1;
                }
            }
            if (s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1]) {
                p = 0;
            }
        }
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != '?' && s[n - i - 1] == '?') {
                s[n - i - 1] = s[i];
                if (s[i] == '0') {
                    zer -= 2;
                }
                else {
                    one -= 2;
                }
            }
            else if (s[i] == '?' && s[n - i - 1] != '?') {
                s[i] = s[n - i - 1];
                if (s[i] == '0') {
                    zer -= 2;
                }
                else {
                    one -= 2;
                }
            }
        }
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == '?' && s[n - i - 1] == '?') {
                if (zer >= 2) {
                    s[i] = s[n - i - 1] = '0';
                    zer -= 2;
                }
                else if (one >= 2) {
                    s[i] = s[n - i - 1] = '1';
                    one -= 2;
                }
                else {
                    p = 0;
 
                }
            }
        }
        if (s[n / 2] == '?') {
            if (zer > 0) {
                s[n / 2] = '0';
                zer -= 1;
            }
            else {
                s[n / 2] = '1';
                one -= 1;
            }
        }
        if (p == 0 || zer != 0 || one != 0) {
            st.push_back("-1");
        }
        else {
            st.push_back(s);
        }
    }
    for (int j = 0; j < st.size(); j++) {
        std::cout << st[j] << std::endl;
    }
}
