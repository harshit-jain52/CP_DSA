#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

vector<ll> sum3(10, 0);

void solve()
{
	int n;
	cin >> n;

	ll ans = 1;
	while (n)
	{
		ans *= sum3[n % 10];
		n /= 10;
	}

	cout << ans << endl;
}

int main()
{
	FASTIO

	for (int num = 0; num <= 9; num++)
		for (int i = 0; i <= num; i++)
			for (int j = 0; j <= num; j++)
				for (int k = 0; k <= num; k++)
					if (i + j + k == num)
						sum3[num]++;

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}