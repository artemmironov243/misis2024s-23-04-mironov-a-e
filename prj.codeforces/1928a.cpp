#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int a, s; cin >> a >> s;
		if ((a & 1 && s & 1) || (s & 1 && a == 2 * s || a & 1 && s == a * 2))
			cout << "NO" << endl;
		else cout << "YES" << endl;
	}return 0;
}