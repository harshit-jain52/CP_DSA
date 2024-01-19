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
	ll x;
	cin >> x;
	if (x == 1)
	{
		cout << -1 << endl;
		return;
	}
	vector<int> output;
	ll num = 0;
	while (((1LL << num) <= x))
		num++;

	num--;

	for (int i = 1; i <= num; i++)
		output.push_back(i);

	ll y = x - (1LL << num);
	for (int i = num; i >= 0; i--)
	{
		if ((1LL << i) & y)
		{
			output.push_back(i + 1);
		}
	}

	cout << output.size() << endl;
	for (auto it : output)
		cout << it << " ";

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