#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < 2 * n; i++, cout << '\n')
            for (int j = 0; j < 2 * n; j++) cout << "#."[((i / 2) ^ (j / 2)) & 1];
    }
}