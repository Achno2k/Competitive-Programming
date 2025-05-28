#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf LLONG_MAX

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> vec;
	for (int i=0; i<n; i++) {
		ll m;
		cin >> m;
		vector<ll> a(m);
		for (int j=0; j<m; j++) {
			cin >> a[j];
		}
		vec.push_back(a);
	}

	// storing all the first and second minimums in pairs
	vector<pair<ll,ll>> arr;
	for (int i=0; i<n; i++) {
		sort(vec[i].begin(), vec[i].end());
		arr.push_back({vec[i][0], vec[i][1]});
	}
	
	// finding the array with the smallest second min and the first min of all 
	ll idx_first = -1;		/// we dont need this tbh but whatever
	ll mn_first = inf;
	ll idx_sec = -1;
	ll mn_sec = inf;
	for (int i=0; i<n; i++) {
		// checking for the first smallest and storing it 
		if (arr[i].first < mn_first) {
			mn_first = arr[i].first;
			idx_first = i;
		}
		// checking for the second smallest and storing it
 		if (arr[i].second < mn_sec) {
			mn_sec = arr[i].second;
			idx_sec = i;
		}
	}

	// adding all the second smallest except for the one with smallest second min
	ll ans = mn_first;
	for (int i=0; i<n; i++) {
		if (i != idx_sec) {
			ans += arr[i].second;
		}
	}

	cout << ans << '\n';
}

int main () {
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}