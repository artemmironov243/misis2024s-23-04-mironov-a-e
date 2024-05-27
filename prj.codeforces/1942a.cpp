#include <bits/stdc++.h>
using namespace std;
int a[1000007];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k == 1) for (int i = 1; i <= n; i++) cout << i << ' '; else
			if (k == n) for (int i = 1; i <= n; i++) cout << 1 << ' '; else cout << -1;
		cout << '\n';
	}
}