#include <iostream>
#include <string>
#include<vector>
int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int n = 0, bl = 0, p = 0;
        std::cin >> n >> bl;
        std::string str;
        std::string last;
        std::vector<int> position;
        std::cin >> str;
        int min = n;
        for (int i = 0; i < bl; i++) {
            if (str[i] == 'B') {
                p += 1;
            }
        }
        last = str[0];
        position.push_back(p);
        for (int i = bl; i < n; i++) {
            if (last == "B") {
                p -= 1;
                if (str[i] == 'B') {
                    p += 1;
                    last = str[i - bl + 1];
                    position.push_back(p);
                }
                else {
                    position.push_back(p);
                    last = str[i - bl + 1];
                }
            }
            else {
                if (str[i] == 'B') {
                    p += 1;
                    last = str[i - bl + 1];
                    position.push_back(p);
                }
                else {
                    position.push_back(p);
                    last = str[i - bl + 1];
                }
            }
        }
        for (int i = 0; i < position.size(); i++) {
            if (bl - position[i] < min) {
                min = bl - position[i];
            }
        }
        std::cout << min << std::endl;
    }
}
