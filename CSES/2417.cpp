#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;
vector<int> freq(N, 0);

int main()
{
	FASTIO

	int n;
	cin >> n;
	int x[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		++freq[x[i]];
	}

	ll suff[N];

	for (int i = N - 1; i >= 1; i--)
	{
		ll ct = 0;
		for (int j = i; j < N; j += i)
			ct += freq[j];

		suff[i] = ct * (ct - 1) / 2;

		for (int j = 2 * i; j < N; j += i)
			suff[i] -= suff[j];
	}

	cout << suff[1];
}