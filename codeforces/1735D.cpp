#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

ll ternary(vector<short> &v)
{
	ll num = 1;
	ll t = 0;
	for (int i = 0; i < v.size(); i++)
	{
		t += v[i] * num;
		num *= 3;
	}
	return t;
}

int main()
{
	FASTIO
	int n, k;
	cin >> n >> k;
	vector<short> c[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int tmp;
			cin >> tmp;
			c[i].push_back(tmp);
		}
	}

	map<ll, int> mp;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			vector<short> v;
			for (int l = 0; l < k; l++)
			{
				int bit = (3 - (c[i][l] + c[j][l]) % 3) % 3;
				v.push_back(bit);
			}
			mp[ternary(v)]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		ll ct = mp[ternary(c[i])];
		ans += ct * (ct - 1) / 2;
	}
	cout << ans << endl;
}