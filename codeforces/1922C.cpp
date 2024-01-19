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
	vector<pair<ll, int>> vec;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back({temp, i});
	}

	sort(vec.begin(), vec.end());
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[vec[i].second] = i;
	ll pref[n], suff[n];
	pref[0] = 0;
	pref[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (vec[i].first - vec[i - 1].first < vec[i - 1].first - vec[i - 2].first)
			pref[i] = pref[i - 1] + 1;
		else
			pref[i] = pref[i - 1] + vec[i].first - vec[i - 1].first;
	}
	suff[n - 1] = 0;
	suff[n - 2] = 1;
	for (int i = n - 3; i >= 0; i--)
	{
		if (vec[i + 1].first - vec[i].first < vec[i + 2].first - vec[i + 1].first)
			suff[i] = suff[i + 1] + 1;
		else
			suff[i] = suff[i + 1] + vec[i + 1].first - vec[i].first;
	}

	int m;
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (x < y)
			cout << pref[mp[y]] - pref[mp[x]];
		else
			cout << suff[mp[y]] - suff[mp[x]];

		cout << endl;
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