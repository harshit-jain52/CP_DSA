#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
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
	int idxn_1 = 0;

	for (int i = 1; i < n; i++)
	{
		cout << "? " << idxn_1 << " " << idxn_1 << " " << i << " " << i << endl;
		char comp;
		cin >> comp;
		if (comp == '<')
			idxn_1 = i;
	}

	vector<int> vec;
	vec.push_back(0);
	for (int i = 1; i < n; i++)
	{
		cout << "? " << idxn_1 << " " << vec[0] << " " << idxn_1 << " " << i << endl;
		char comp;
		cin >> comp;
		if (comp == '>')
			continue;
		if (comp == '<')
			vec.clear();
		vec.push_back(i);
	}

	int idx = vec[0];
	for (int it : vec)
	{
		cout << "? " << idx << " " << idx << " " << it << " " << it << endl;
		char comp;
		cin >> comp;
		if (comp == '>')
			idx = it;
	}

	cout << "! " << idxn_1 << " " << idx << endl;
}

int main()
{
	// FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}