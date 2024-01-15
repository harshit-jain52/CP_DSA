#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef unsigned long long ull;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	ull n;
	cin >> n;
	n--;
	if (n == 0)
		cout << 0;
	vector<int> vec;
	while (n >= 5)
	{
		vec.push_back(2 * (n % 5));
		n /= 5;
	}
	if (n > 0)
		vec.push_back(2 * n);

	reverse(vec.begin(), vec.end());
	for (int dig : vec)
		cout << dig;
}