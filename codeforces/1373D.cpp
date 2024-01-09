#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const ll INF = 1e15;

ll maxSubArray(ll nums[], int n, int rem)
{
	ll max_so_far = -INF, max_ending_here = 0;

	for (int i = 0; i < n; i++)
	{
		max_ending_here += nums[i];
		if (i % 2 == rem)
			max_so_far = max(max_so_far, max_ending_here);
		if (i % 2 == rem && max_ending_here < 0)
			max_ending_here = 0;
	}

	return max(max_so_far, 0LL);
}

void solve()
{
	int n;
	cin >> n;
	ll a[n];
	ll evensum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i % 2 == 0)
		{
			evensum += a[i];
			a[i] = -a[i];
		}
	}

	cout << evensum + max(maxSubArray(a, n, 0), maxSubArray(a, n, 1)) << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}