#include<bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << ((a + b + c) % 2 ? -1 : min((a + b + c) / 2, a + b)) << endl;
    }
}
