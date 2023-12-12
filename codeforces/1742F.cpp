#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool check(vector<ll> &s, vector<ll> &t)
{
	int idx = -1;
	for (int i = 0; i < 26; i++)
	{
		if (s[i] > 0)
		{
			idx = i;
			break;
		}
	}

	if (idx == -1)
		return true;

	for (int i = idx + 1; i < 26; i++)
	{
		if (t[i] > 0)
			return true;
	}

	int idx2 = -1;
	for (int i = 25; i >= 0; i--)
	{
		if (s[i] > 0)
		{
			idx2 = i;
			break;
		}
	}

	int idx3 = -1;
	for (int i = 0; i < 26; i++)
	{
		if (t[i] > 0)
		{
			idx3 = i;
			break;
		}
	}

	if (idx == idx2)
	{
		if (t[idx] > s[idx] || (t[idx] == s[idx] && idx3 != idx))
			return true;
	}

	return false;
}

void solve()
{
	int q;
	cin >> q;
	vector<ll> s(26, 0), t(26, 0);
	s[0]++;
	t[0]++;

	while (q--)
	{
		int d, k;
		string x;
		cin >> d >> k >> x;

		if (d == 1)
		{
			for (int i = 0; i < x.size(); i++)
			{
				s[x[i] - 'a'] += k;
			}
		}
		else
		{
			for (int i = 0; i < x.size(); i++)
			{
				t[x[i] - 'a'] += k;
			}
		}

		if (check(s, t))
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
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