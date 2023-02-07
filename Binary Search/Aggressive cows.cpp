#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define pb push_back
#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool isTrue(ll a[], int n, int c, int maxdist) {
	int start = a[0], i = 1, count = 1;
	while (i < n) {
		if ((a[i] - start) >= maxdist) {
			start = a[i];
			count++;
		}
		i++;
	}
	if (count >= c)
		return true;
	else
		return false;
}

int main() {
	fastio;

	int n, c;
	cin >> n >> c;
	ll a[n];

	rep(i, n) {
		cin >> a[i];

	}
	sort(a, a + n);
	int s = 0;
	int e = a[n - 1] - a[0];
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (isTrue(a, n, c, mid)) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans << endl;



	return 0;
}
// JrphaOcrky