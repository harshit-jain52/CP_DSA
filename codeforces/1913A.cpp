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
	int i, n = s.size();
	int a = s[0] - '0', b = 0;

	for (i = 1; i < n; i++)
	{
		if (s[i] != '0')
			break;
		a = a * 10;
	}
	for (; i < n; i++)
	{
		b = b * 10 + (s[i] - '0');
	}

	if (b > a)
		cout << a << " " << b;
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