#include <bits/stdc++.h>
using namespace std;

int t, n, q, x, y, z;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> mp;
		y = 0;
		while (n--) {
			cin >> x;
			y += ((++mp[x]) == 2);
		}
		cout << y << '\n';
	}
}