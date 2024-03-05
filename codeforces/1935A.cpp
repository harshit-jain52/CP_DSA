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
	int m = s.size();
	int i = 0, j = m - 1;

	int flag = 0;
	while (i <= j)
	{
		if (s[i] < s[j])
			break;
		if (s[i] > s[j])
		{
			flag = 1;
			break;
		}
		i++;
		j--;
	}

	if (!flag)
		cout << s << endl;
	else
	{
		string r = s;
		reverse(r.begin(), r.end());
		cout << r << s << endl;
	}
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