#include<bits/stdc++.h>
using namespace std;
int x, test;
int main()
{
	scanf("%d", &test);
	for (; test--;)
	{
		scanf("%d", &x);
		printf("%d\n", (1 << (__lg(x))));
	}
	return 0;
}
