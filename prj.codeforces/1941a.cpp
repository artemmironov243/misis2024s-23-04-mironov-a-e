#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k, c = 0; cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for (auto& i : a)cin >> i;
        for (auto& i : b)cin >> i;
        for (int i : a)for (int j : b) c += i + j <= k;
        cout << c << '\n';
    }
    return 0;
}