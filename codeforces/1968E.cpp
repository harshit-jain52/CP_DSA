#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

inline void print(int x, int y)
{
	cout << x << " " << y << endl;
}

void solve()
{
	int n;
	cin >> n;
	print(1, 1);
	print(1, 2);
	for (int i = 3; i <= n; i++)
		print(i, i);
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