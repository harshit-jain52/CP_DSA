#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	int n, t;
	cin >> n >> t;
	vector<ll> score(n + 1, 0);
	map<ll, int> mp;
	mp[0] = n;

	while (t--)
	{
		int a, b;
		cin >> a >> b;
		mp[score[a]]--;
		if (mp[score[a]] == 0)
			mp.erase(score[a]);
		score[a] += b;
		mp[score[a]]++;
		cout << mp.size() << endl;
	}
}