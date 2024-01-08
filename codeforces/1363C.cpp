#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1005;

bool solve()
{
	int n, x;
	cin >> n >> x;

	vector<int> numEdges(n + 1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		numEdges[u]++;
		numEdges[v]++;
	}

	if (numEdges[x] == 1 || n == 1)
		return true;

	int removed = (n - 2);

	return removed % 2 == 0;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		if (solve())
			cout << "Ayush";
		else
			cout << "Ashish";
		cout << endl;
	}
}