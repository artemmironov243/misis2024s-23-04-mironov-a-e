#include <bits/stdc++.h>
using namespace std;

int n;
char c[500005];
pair <int, int> a[500005];

int main() {
	scanf("%s", c + 1);
	n = strlen(c + 1);
	int s = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = { s,n - i };
		if (c[i] == '(') s++;
		else s--;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) printf("%c", c[n - a[i].second]);

	return 0;
}