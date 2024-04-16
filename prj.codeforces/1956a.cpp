#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, q, x, a[200010];
	cin >> t;
	while (t--)
	{
		cin >> n >> q;
		for (int i = 1; i <= n; i++)  cin >> a[i];
		while (q--)
		{
			cin >> x;
			cout << min(x, a[1] - 1) << " ";
		}
		cout << endl;
	}
}