#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		long long a[11];
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		cout << (a[n - 2] == a[n - 1] ? "SQUARE" : "TRIANGLE") << endl;
	}
}