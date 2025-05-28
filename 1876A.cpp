// 1876A --> 1000 (Greedy and Sortings) 
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf LLONG_MAX

void solve() {
	ll n, p;
	cin >> n >> p;
	vector<ll> a(n), b(n);
	vector<pair<ll,ll>> c(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	for (int i=0; i<n; i++) {
		c[i] = {b[i], a[i]};
	}
	// sort the vector according to the increasing cost
	sort (c.begin(), c.end());

	ll already_shared = 1;
	ll min_cost = p;
	for (auto it: c) {
		ll curr_cost = it.first;
		ll can_be_shared = it.second;

		// if the individual cost is greater than the leader cost
		// then have the leader to tell to the remaining residents
		if (curr_cost >= p) {
			break;
		}
		// if all the residents are exhausted then add the cost of the 
		// remaining residents and break
		if (already_shared + can_be_shared >= n) {
			min_cost += (n - already_shared) * curr_cost;
			already_shared = n;
			break;
		} else {
			// if the residents won't be completed, then add the current cost
			// to the overall answer and keep doing it
			min_cost += can_be_shared * curr_cost;
			already_shared += can_be_shared;
		}
	}
	// add the leader's cost if needed (automatically 0 will be added if
	// all the residents already know)
	min_cost += (n - already_shared) * p;
	cout << min_cost << '\n';
}

int main () {
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}