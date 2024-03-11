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
	int n;
	cin >> n;
	ll a[n];
	ll sum = 0;
	ll maxE = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		maxE = max(maxE, a[i]);
	}
	if (sum % 2 == 1)
		return false;
	// ll maxE = *max_element(a,a+n);
	if (maxE * 2 > sum)
		return false;

	return true;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		if (solve())
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}