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
	int ans[n + 1];
	int num = 1;
	priority_queue<pair<int, int>> pq;
	pq.push({n, -1});

	while (!pq.empty())
	{
		auto p = pq.top();
		int len = p.first, l = -p.second;
		int r = l + len - 1;
		pq.pop();
		int idx;

		if (len <= 0)
			break;
		if (len % 2 == 1)
			idx = (l + r) / 2;
		else
			idx = (l + r - 1) / 2;

		ans[idx] = num++;
		pq.push({idx - l, -l});
		pq.push({r - idx, -(idx + 1)});
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
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