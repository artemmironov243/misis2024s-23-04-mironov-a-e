#include<bits/stdc++.h>
using namespace std;
int main() {
	int t, n, k;
	for (cin >> t; t--;) {
		cin >> n >> k;
		cout << (k >= n - 1 ? 1 : n) << "\n";
	}
}