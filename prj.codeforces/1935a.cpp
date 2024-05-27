#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		string news = s;
		reverse(news.begin(), news.end());
		cout << min(s, news + s) << "\n";
	}

}