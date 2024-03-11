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
	int n;
	cin >> n;
	string s;
	cin >> s;

	int MAPIE = 0, MAP = 0, PIE = 0;
	for (int i = 0; i < n - 2; i++)
	{
		if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p')
			MAP++;
		else if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e')
			PIE++;
	}

	for (int i = 0; i < n - 4; i++)
	{
		if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p' && s[i + 3] == 'i' && s[i + 4] == 'e')
			MAPIE++;
	}

	cout << (MAP + PIE - MAPIE) << endl;
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