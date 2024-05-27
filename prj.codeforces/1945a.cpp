# include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		if ((b + c) % 3 > c) cout << -1 << endl;
		else cout << (b + c + 2) / 3 + a << endl;
	}
}