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
	int x, y;
	cin >> x >> y;

	// a = (a%b)*(b+1) --> a/(b+1) = a%b --> a&b <= root(a)
	// num=a%b, num<=root(x), num<b<=x/num-1
	ll ct = 0;
	for (int num = 1; num * num <= x; num++)
		ct += max(0, (min(y, x / num - 1) - num));

	cout << ct << endl;
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