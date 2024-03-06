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
	string s;
	cin >> s;
	int n = s.size();
	int pref[26][n + 1];
	vector<int> occ(26, 0);
	for (int j = 0; j < 26; j++)
		pref[j][0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			pref[j][i + 1] = pref[j][i] + (s[i] == 'a' + j);
		}
		occ[s[i] - 'a']++;
	}

	int ans = n;
	for (int j = 0; j < 26; j++)
	{
		if (occ[j] == 0)
			continue;
		if (occ[j] == 1)
		{
			ans = 0;
			break;
		}

		for (int l = 1; l + occ[j] - 1 <= n; l++)
		{
			ans = min(ans, pref[j][l - 1] + pref[j][n] - pref[j][l + occ[j] - 1]);
		}
	}
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