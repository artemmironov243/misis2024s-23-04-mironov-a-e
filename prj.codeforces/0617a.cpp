#include <iostream>
int main() {
    int w = 0;
    int p = 0;
    std::cin >> w;
    if (w % 5 == 0) {
        p =  w / 5;
        std::cout << p;
    } else {
        p = w / 5 + 1;
        std::cout << p;  
    }   
}
