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
	int n, i;
	cin >> n;
	vector<pair<ll, ll>> printer;

	for (i = 0; i < n; i++)
	{
		ll t, d;
		cin >> t >> d;
		printer.push_back({t, t + d});
	}

	sort(printer.begin(), printer.end());
	priority_queue<ll> pq;
	ll time = 1;
	int ct = 0;
	i = 0;

	while (time++)
	{
		if (pq.empty())
		{
			if (i == n)
				break;
			time = printer[i].first;
		}

		while (i < n && printer[i].first == time)
			pq.push(-printer[i++].second);

		while (!pq.empty() && -pq.top() < time)
			pq.pop();

		if (!pq.empty())
		{
			pq.pop();
			ct++;
		}
	}

	cout << ct << endl;
}