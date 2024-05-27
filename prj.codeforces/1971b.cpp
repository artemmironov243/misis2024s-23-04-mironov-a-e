#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
whilet:
    while (t--) {
        string s; cin >> s; int j = 0;
        for (int i = 0; i < s.length(); i++) if (s[i] != s[j]) { char t; t = s[i], s[i] = s[j], s[j] = t; cout << "Yes" << '\n' << s << '\n'; goto whilet; }
        cout << "no" << '\n';
    }
}