#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf LLONG_MAX
#define inff 1e9
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<int> arr(n);
	int evenCnt = 0;

	// getting the input and counting the even numbers
	for (int i=0; i<n; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 0) evenCnt += 1;
	}

	// checking if the product is already divisible by 'k'
	for (int i=0; i<n; i++) {
		if (arr[i] % k == 0) {
			cout << 0 << '\n';
			return;
		}
	}

	// algo to find the min no. of operations
	int mn = 1e9;
	for (int i=0; i<n; i++) {
		int quotient = arr[i] / k;
		int required = k * (quotient + 1);
		mn = min (mn, abs(arr[i] - required));
	}

	// handling the k = 4 case differently by checking the min op. from 
	// several cases and k = 2,3,5 prime numbers differently
 	if (k == 4) {
 		cout << min (mn, max(0, 2 - evenCnt)) << '\n';
 	} else {
 		cout << mn << '\n';
 	}
}

int main () {
	ll t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}