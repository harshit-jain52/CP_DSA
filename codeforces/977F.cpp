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
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp;
	int ans = 0, last = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]] = max(mp[a[i]], 1 + mp[a[i] - 1]);
		if (mp[a[i]] > ans)
		{
			ans = mp[a[i]];
			last = a[i];
		}
	}
	cout << ans << endl;
	vector<int> pos;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == last)
		{
			pos.push_back(i + 1);
			last--;
		}
	}
	reverse(pos.begin(), pos.end());
	for (int p : pos)
		cout << p << " ";
}