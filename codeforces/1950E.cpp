#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> divis[N];

void divisors()
{
	for (int i = 0; i < N; i++)
		divis[i].push_back(1);

	for (int i = 2; i < N; i++)
		for (int j = i; j < N; j += i)
			divis[j].push_back(i);
}

string operator*(string &str, int num)
{
	string result = "";
	while (num--)
	{
		result += str;
	}
	return result;
}

bool isOkay(const string &s, const string &t)
{
	if (s.size() != t.size())
		return false;
	int ct = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != t[i])
			ct++;
		if (ct > 1)
			return false;
	}
	return true;
}

int solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int d : divis[n])
	{
		// cout << d << " ";
		string pref = s.substr(0, d);
		string suff = s.substr(n - d, d);
		// cout << pref << " " << suff << endl;

		if (isOkay(s, pref * (n / d)))
			return d;
		if (isOkay(s, suff * (n / d)))
			return d;
	}
	return -1;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	divisors();
	while (t--)
	{
		cout << solve() << endl;
	}
}