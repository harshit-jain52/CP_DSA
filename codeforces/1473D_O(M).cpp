#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define pii pair<int, int>
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e7;
void solve()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int pref[n + 1];
	vector<pii> fromleft(n + 1), fromright(n + 2);
	pref[0] = 0;
	fromleft[0] = {-INF, INF};

	for (int i = 0; i < n; i++)
	{
		pref[i + 1] = pref[i] + ((s[i] == '+') ? 1 : -1);
		fromleft[i + 1] = {max(pref[i + 1], fromleft[i].first), min(pref[i + 1], fromleft[i].second)};
	}

	fromright[n + 1] = {-INF, INF};
	for (int i = n; i > 0; i--)
	{
		fromright[i] = {max(pref[i], fromright[i + 1].first), min(pref[i], fromright[i + 1].second)};
	}

	while (m--)
	{
		int l, r, upper, lower;
		cin >> l >> r;
		upper = max(0, max(fromleft[l - 1].first, pref[l - 1] + fromright[r + 1].first - pref[r]));
		lower = min(0, min(fromleft[l - 1].second, pref[l - 1] + fromright[r + 1].second - pref[r]));
		cout << 1 + upper - lower << endl;
	}
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