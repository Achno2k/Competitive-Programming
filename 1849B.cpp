#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf LLONG_MAX
#define pii pair<int,int>
#define pll pair<long long, long long>

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (auto& el: arr) cin >> el;

	vector<pll> a(n);
	for (int i=0; i<n; i++) {
		if (arr[i] % k != 0) {
			arr[i] %= k;
		} else {
			arr[i] = k;
		}
		a[i] = {arr[i], i};
	}

	sort(a.begin(), a.end(), [&](pll& a, pll& b) {
		if (a.first != b.first) {
			return a.first > b.first;
		}
		return a.second < b.second;
	});

	for (auto it: a) {
		cout << it.second + 1 << " ";
	}
	cout << endl;
}

int main () {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}