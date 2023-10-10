#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	string s;
	cin >> s;
	ll n = s.size(), pos;
	cin >> pos;

	int mark[n] = {0};
	int curr = n;
	stack<int> st;

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && s[st.top()] > s[i])
		{
			mark[st.top()] = curr--;
			st.pop();
		}

		st.push(i);
	}

	while (!st.empty())
	{
		mark[st.top()] = curr--;
		st.pop();
	}

	// for(int i=0;i<n;i++)
	// 	cout << mark[i]<<" ";
	// cout << endl;

	ll posFromEnd = n * (n + 1) / 2 - pos + 1;
	ll len; // length of string in which pos is
	for (ll i = 1; i <= n; i++)
	{
		if (i * (i + 1) / 2 >= posFromEnd)
		{
			len = i;
			break;
		}
	}

	ll actualPos = pos - (n * (n + 1) / 2 - len * (len + 1) / 2);
	// cout << len << " " << actualPos <<endl;
	int ct = 0;

	for (int i = 0; i < n; i++)
	{
		if (mark[i] <= len)
			ct++;
		if (ct == actualPos)
		{
			cout << s[i];
			return;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}