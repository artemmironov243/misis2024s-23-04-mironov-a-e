#include <iostream>
#include <string>

int main() {
    int n = 0, k = 0, i = 0, t = 0;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        std::string s;
        bool f = true;
        s.reserve(300000);
        s.resize(n);
        for (i = 0; i < n; i++) {
            std::cin >> s[i];
        }


        for (i = 0; i < k; i++) {
            if (s[i] == '?') {
                for (int j = i + k; j < n; j += k) {
                    if (s[j] != '?') {
                        s[i] = s[j];
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < k; i++) {
            if (s[i] != '?') {
                for (int j = i + k; j < n; j += k) {
                    if (s[j] == '?')
                        s[j] = s[i];
                    else if (s[j] != s[i]) {
                        f = false;
                    }
                }
            }
        }

        int a = 0;
        int b = 0;
        for (i = 0; i < k; i++) {
            if (s[i] == '0')
                a++;
            if (s[i] == '1')
                b++;
        }
        if ((a <= k / 2) && (b <= k / 2) && f == true) {
            std::cout << "YES" << "\n";
        }
        else {
            std::cout << "NO" << "\n";
        }
    }
}
