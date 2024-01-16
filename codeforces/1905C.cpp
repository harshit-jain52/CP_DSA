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
	string s;
	cin >> s;

	char maxright[n];
	maxright[n - 1] = s[n - 1];
	for (int i = n - 2; i >= 0; i--)
		maxright[i] = max(maxright[i + 1], s[i]);

	vector<int> indices;
	for (int i = 0; i < n; i++)
		if (maxright[i] == s[i])
			indices.push_back(i);
	int sz = indices.size();

	int pref = 1;
	for (int i = 1; i < sz; i++)
	{
		if (s[indices[i]] == s[indices[i - 1]])
		{
			pref++;
		}
		else
			break;
	}

	for (int i = 0, j = sz - 1; i <= j; i++, j--)
	{
		swap(s[indices[i]], s[indices[j]]);
	}

	bool flag = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] > s[i + 1])
		{
			flag = false;
			break;
		}
	}

	if (flag)
		cout << sz - pref;
	else
		cout << -1;
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