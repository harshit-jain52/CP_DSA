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
	vector<pair<int, int>> endpts;
	ll c[n];
	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		endpts.push_back({l, 0});
	}

	for (int i = 0; i < n; i++)
	{
		int r;
		cin >> r;
		endpts.push_back({r, 1});
	}

	for (int i = 0; i < n; i++)
		cin >> c[i];

	sort(endpts.begin(), endpts.end());
	stack<int> st;
	vector<int> lengths;
	for (auto pt : endpts)
	{
		if (pt.second == 0)
			st.push(pt.first);
		else
		{
			lengths.push_back(pt.first - st.top());
			st.pop();
		}
	}

	sort(lengths.begin(), lengths.end());
	sort(c, c + n);

	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += c[n - 1 - i] * lengths[i];

	cout << sum << endl;
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