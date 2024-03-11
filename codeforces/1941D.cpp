#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1005;

void solve()
{
	int n, m, x;
	cin >> n >> m >> x;
	int r[m];
	char c[m];
	for (int i = 0; i < m; i++)
	{
		cin >> r[i] >> c[i];
	}
	x--;
	set<int> tmp;
	queue<int> q;
	tmp.insert(x);

	for (int i = 0; i < m; i++)
	{
		for (int it : tmp)
			q.push(it);
		tmp.clear();
		int sz = q.size();
		while (sz--)
		{
			int curr = q.front();
			q.pop();
			int num0 = (curr + r[i]) % n;
			int num1 = (curr - r[i] + n) % n;
			if (c[i] == '?')
			{
				tmp.insert(num0);
				if (num0 != num1)
					tmp.insert(num1);
			}
			else if (c[i] == '0')
				tmp.insert(num0);
			else
				tmp.insert(num1);
		}
	}

	cout << tmp.size() << endl;
	for (int it : tmp)
		cout << it + 1 << " ";
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