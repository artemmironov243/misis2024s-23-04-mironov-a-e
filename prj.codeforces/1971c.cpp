#include<iostream>
using namespace std;
int main() {
	int t, a, b, c, d, tmp;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		if (a > b) { tmp = a; a = b; b = tmp; }
		cout << ((a < c && c < b) != (a < d && d < b) ? "YES\n" : "NO\n");
	}
}
