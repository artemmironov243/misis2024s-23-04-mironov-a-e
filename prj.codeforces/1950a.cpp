#include<iostream>
using namespace std;

int n, a, b, c;
int main() {
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		if (a < b && b < c)cout << "STAIR\n";
		else if (a<b && b>c)cout << "PEAK\n";
		else cout << "NONE\n";
	}
}