#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define ppi pair<int, int>
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
	int n;
	cin >> n;
	vector<ppi> v(2 * n + 1);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		v[a] = {i, 0};
		v[b] = {i, 1};
	}

	stack<int> st;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (v[i].second == 0)
			st.push(v[i].first);
		else
		{
			if (st.empty())
				return true;
			if (st.top() != v[i].first)
				return true;
			st.pop();
		}
	}
	return false;
}

int main()
{
	FASTIO
	if (solve())
		cout << "Yes";
	else
		cout << "No";
}