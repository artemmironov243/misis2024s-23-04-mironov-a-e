#include<iostream>
using namespace std;
int n, a, b, c;
int main() {
	cin >> n;
	while (n--) {
		cin >> a;
		c = 0;
		int arr[1000] = { 0 };
		for (int i = 0; i < a; i++) {
			cin >> b;
			arr[b]++;
		}
		for (int j = 0; j < 101; j++) {
			c += arr[j] / 3;
		}
		cout << c << endl;
	}
	return 0;
}