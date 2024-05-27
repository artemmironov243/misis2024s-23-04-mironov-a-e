#include<bits/stdc++.h>
using namespace std;
int T, n, k;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        cout << (k + 1) / 2 + (k == 4 * n - 2) << endl;
    }
}