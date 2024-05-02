#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
map<int, set<int>> idx1;
map<int, set<int>> idx2;

void solve()
{
	int n, q;
	cin >> n >> q;
	int a[n];
	int prefxor[n + 1], suffxor[n + 2];
	prefxor[0] = 0;
	suffxor[n + 1] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		prefxor[i] = a[i - 1] ^ prefxor[i - 1];
		idx1[prefxor[i]].insert(i);
	}
	for (int i = n; i >= 1; i--)
	{
		suffxor[i] = a[i - 1] ^ suffxor[i + 1];
		idx2[suffxor[i]].insert(-i);
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int x = prefxor[r] ^ prefxor[l - 1];
		if (x == 0)
		{
			cout << "YES" << endl;
			continue;
		}
		int y1 = x ^ prefxor[l - 1];
		int y2 = x ^ suffxor[r + 1];
		auto it1 = idx1[y1].lower_bound(l);
		auto it2 = idx2[y2].lower_bound(-r);
		if (it1 == idx1[y1].end() || it2 == idx2[y2].end() || ((*it1) >= r) || (-(*it2) <= l) || (*it1) == -(*it2))
		{
			cout << "NO" << endl;
			continue;
		}

		if ((((*it1) == -(*it2) - 1) && a[(*it1)] == x) || prefxor[-(*it2) - 1] ^ prefxor[(*it1)] == x)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		idx1.clear();
		idx2.clear();
		solve();
		cout << endl;
	}
}