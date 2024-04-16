#include<iostream>
#include<cstdio>
using namespace std;
int t, hh, mm;
int main() {
	cin >> t;
	while (t--) {
		scanf("%d:%d", &hh, &mm);
		printf("%02d:%02d %s\n", (hh + 11) % 12 + 1, mm, (hh < 12) ? "AM" : "PM");

	}
	return 0;
}