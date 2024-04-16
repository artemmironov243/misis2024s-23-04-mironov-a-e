#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int a; cin >> a; while (a--) {
        ll n, k, t = 0; cin >> n >> k; ll b[n]; ll u = k / 2 + k % 2, v = k / 2;
        for (int i = 0; i<n && cin >> b[i]; i++) if (b[i] <= u) u -= b[i], b[i] = 0; else b[i] -= u, u = 0;
        for (int i = n - 1; i >= 0; i--) if (b[i] <= v) v -= b[i], b[i] = 0; else b[i] -= v, v = 0;
        for (int i = 0; i < n; i++) if (b[i] == 0) t++; cout << t << endl;
    }
}