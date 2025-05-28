#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf LLONG_MAX

void solve() {
	string s;
	cin >> s;
	int cnt0 = 0;
	int cnt1 = 0;
	for (char ch: s) {
		if (ch == '0') cnt0++;
		else cnt1++;
	}
	string t = "";
	for (char ch: s) {
		if (ch == '0') {
			if (cnt1 > 0) {
				t += '1';
				cnt1--;
			} else break;
		} else {
			if (cnt0 > 0) {
				t += '0';
				cnt0--;
			} else break;
		}
	}
	cout << s.size() - t.size() << '\n';
}

int main () {
	ll t;
	cin >> t;
	while (t--) 
		solve();
	return 0;
}