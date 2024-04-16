#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, c, d;
	map<int, int>f;
	cin >> n >> c >> d;
	int bg = 1e9;
	for (int i = 1; i <= n * n; i++) {
		int b;
		cin >> b;
		f[b]++;
		bg = min(bg, b);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			f[bg + i * c + j * d]--;
		}
	for (auto v : f)if (v.second) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main() {
	int t;
	cin >> t;
	while (t--)solve();
}