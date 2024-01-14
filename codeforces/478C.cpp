#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int max3(int a, int b, int c)
{
	return max(a, max(b, c));
}

int main()
{
	FASTIO
	ll r, g, b;
	cin >> r >> g >> b;
	ll tot = r + g + b;

	if (max3(r, g, b) >= 2 * (tot - max3(r, g, b)))
		cout << tot - max3(r, g, b);
	else
		cout << tot / 3;
}