#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5;
int main()
{
	FASTIO
	int n;
	cin >> n;
	set<int> missing;
	for (int i = 0; i <= n; i++)
		missing.insert(i);

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		if (missing.find(p) != missing.end())
			missing.erase(p);
		cout << *missing.begin() << endl;
	}
}