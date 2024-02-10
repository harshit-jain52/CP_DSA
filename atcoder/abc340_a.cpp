#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	int a, b, d;
	cin >> a >> b >> d;

	int n = (b - a) / d;

	for (int i = 0; i <= n; i++)
		cout << a + i * d << " ";
}