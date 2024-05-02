#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

string solve()
{
	int n, k, b, s;
	cin >> n >> k >> b >> s;
	int p[n + 1];
	ll a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	auto score = [&](int pos) -> ll
	{
		vector<bool> reach(n + 1, false);
		vector<int> moves;
		int curr = pos;

		while (!reach[curr])
		{
			reach[curr] = true;
			moves.push_back(curr);
			curr = p[curr];
		}

		moves.resize(min((int)moves.size(), k));
		ll ans = 0, pref = 0;
		for (int i = 0; i < moves.size(); i++)
		{
			ans = max(ans, pref + (k - i) * a[moves[i]]);
			pref += a[moves[i]];
		}
		return ans;
	};

	ll sb = score(b), ss = score(s);
	if (sb > ss)
		return "Bodya";
	if (sb < ss)
		return "Sasha";
	return "Draw";
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		cout << solve() << endl;
	}
}