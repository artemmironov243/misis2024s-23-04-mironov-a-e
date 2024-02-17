#include <iostream>
int main() {
 
    int y = 0;
    std::cin >> y;
    int x = 1000;
    int w = 1000;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    while (x < 10000) {
        x += 1;
        w = x;
        if (x > y) {
            a = w % 10;
            w /= 10;
            b = w % 10;
            w /= 10;
            c = w % 10;
            w /= 10;
            d = w % 10;
            w /= 10;
            if (a != b && c != d && a != c && a != d && b != c && b != d) {
                std::cout << x;
                break;
            }
        }
 
    } 
}
