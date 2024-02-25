#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
	int n, m;
	cin >> n >> m;
	string a[n];
	int trail0[n];
	int ct = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ct += a[i].length();
		trail0[i] = 0;
		for (int j = a[i].length() - 1; j >= 0; j--)
		{
			if (a[i][j] != '0')
				break;
			trail0[i]++;
		}
		trail0[i] *= (-1);
	}

	sort(trail0, trail0 + n);
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			ct += trail0[i];

	return (ct > m);
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		if (solve())
			cout << "Sasha";
		else
			cout << "Anna";
		cout << endl;
	}
}