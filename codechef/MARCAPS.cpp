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
	pair<int, int> a[n];
	map<int, int> freq;
	int maxfreq = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
		freq[a[i].first]++;
		maxfreq = max(maxfreq, freq[a[i].first]);
	}

	if (maxfreq > n / 2)
	{
		cout << "No" << endl;
		return;
	}

	sort(a, a + n);
	// rotate by maxfreq
	int ind[n];
	for (int i = 0; i < n; i++)
		ind[i] = a[i].second;
	reverse(ind, ind + maxfreq);
	reverse(ind + maxfreq, ind + n);
	reverse(ind, ind + n);
	int ans[n];
	for (int i = 0; i < n; i++)
		ans[ind[i]] = a[i].first;
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++)
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