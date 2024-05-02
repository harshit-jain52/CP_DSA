#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9 + 1;
int main()
{
	FASTIO
	int n;
	cin >> n;
	int a[n + 2];
	a[0] = a[n + 1] = -INF;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int next[n + 2], prev[n + 2];
	stack<int> st;

	st.push(0);
	for (int i = 1; i <= n; i++)
	{
		while (!st.empty() && a[st.top()] >= a[i])
			st.pop();

		prev[i] = st.top();
		st.push(i);
	}

	st.push(n + 1);
	for (int i = n; i >= 1; i--)
	{
		while (!st.empty() && a[st.top()] >= a[i])
			st.pop();

		next[i] = st.top();
		st.push(i);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int len = next[i] - prev[i] - 1;
		ans = max(ans, len * 1LL * a[i]);
	}

	cout << ans;
}