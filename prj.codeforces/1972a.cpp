#include <iostream>
using namespace std;
int t, n, a[101], b[101];
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		int j = 0, i = 0;
		while (n--) {
			if (a[i] > b[j])j++;
			else i++, j++;
		}
		cout << j - i << '\n';
	}
}