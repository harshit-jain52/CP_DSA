#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
map<int, set<int>> idx;

void solve()
{
	int n, q;
	cin >> n >> q;
	int a[n];
	int prefxor[n + 1];
	prefxor[0] = 0;
	idx[0].insert(0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		prefxor[i + 1] = a[i] ^ prefxor[i];
		idx[prefxor[i + 1]].insert(i + 1);
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		if (prefxor[r] == prefxor[l - 1]) // 2 segments
			cout << "YES" << endl;
		else
		{
			// 3 segments: [l,x] [x+1,y] [y+1,r]
			auto itx = idx[prefxor[r]].lower_bound(l);		   // smallest x>=l s.t. prefxor[x] = prefxor[r]
			auto ity = --(idx[prefxor[l - 1]].lower_bound(r)); // largest y<=r s.t. prefxor[y] = prefxor[l-1]

			if ((*itx) < (*ity))
				cout << "YES" << endl;
			else
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
		idx.clear();
		solve();
		cout << endl;
	}
}