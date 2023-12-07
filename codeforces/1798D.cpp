#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	ll a[n], maxa = INT_MIN, mina = INT_MAX;
	vector<ll> neg, pos;
	int zeroes = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		maxa = max(maxa, a[i]);
		mina = min(mina, a[i]);

		if (a[i] > 0)
			pos.push_back(a[i]);
		else if (a[i] < 0)
			neg.push_back(a[i]);
		else
			zeroes++;
	}

	if (zeroes == n)
	{
		cout << "No" << endl;
		return;
	}

	cout << "Yes" << endl;
	int negsz = neg.size(), possz = pos.size();
	int i = 0, j = 0;
	ll prefsum = 0;

	while (i < negsz || j < possz)
	{
		if (j < possz && pos[j] + prefsum >= maxa - mina)
		{
			cout << neg[i] << " ";
			prefsum += neg[i++];
		}
		else if (i < negsz && neg[i] + prefsum <= mina - maxa)
		{
			cout << pos[j] << " ";
			prefsum += pos[j++];
		}
		else
		{
			if (j < possz)
			{
				cout << pos[j] << " ";
				prefsum += pos[j++];
			}
			else
			{
				cout << neg[i] << " ";
				prefsum += neg[i++];
			}
		}
	}

	while (zeroes--)
		cout << 0 << " ";
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}