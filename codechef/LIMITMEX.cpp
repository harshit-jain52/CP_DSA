#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// Contribution of a subarray S = max(S)-numDistinct(S)+1

	// 1. Sum of numDistinct(S)
	ll dp1[n]; // dp1[i] = sum of numDistinct(S) of all subarrays S starting at i
	vector<int> pos(n, n);
	dp1[n - 1] = 1;
	pos[a[n - 1]] = n - 1;
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] == a[i + 1])
			dp1[i] = dp1[i + 1] + 1;
		else
			dp1[i] = dp1[i + 1] + (pos[a[i]] - i);
		pos[a[i]] = i;
	}
	// for(int i=0;i<n;i++) cout << dp1[i] << " ";
	// cout << endl;
	ll sum1 = 0;
	for (int i = 0; i < n; i++)
		sum1 += dp1[i];

	// 2. Sum of Max(S)
	ll dp2[n + 1]; // dp2[i] = sum of max(S) of all subarrays S starting at i
	dp2[n] = 0;
	vector<int> nge(n, n);
	stack<int> st;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && a[st.top()] <= a[i])
			st.pop();
		if (!st.empty())
			nge[i] = st.top();
		st.push(i);

		dp2[i] = dp2[nge[i]] + a[i] * 1LL * (nge[i] - i);
	}

	// for(int i=0;i<n;i++) cout << dp2[i] << " ";
	// cout << endl;
	ll sum2 = 0;
	for (int i = 0; i < n; i++)
		sum2 += dp2[i];

	// Total
	ll ans = sum2 - sum1 + (n * 1LL * (n + 1)) / 2;
	cout << ans << endl;
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