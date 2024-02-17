#include <iostream>
#include <string>
int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int n = 0, p = 1;
        std::string st;
        std::cin >> n >> st;
        for (int i = 0; i < n; i++) {
            int blue = 0, red = 0;
            while (st[i] != 'W' && i != n - 1) {
                if (st[i] == 'B') {
                    blue += 1;
                }
                else {
                    red += 1;
                }
                i++;
            }
            if (st[i] == 'B') {
                blue += 1;
            }
            else if(st[i] == 'R') {
                red += 1;
            }
            if (red == blue || red > 0 && blue > 0){
            }
            else {
                p = 0;
                break;
            }
        }
        if (p == 1) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
}
