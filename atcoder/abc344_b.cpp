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
	stack<int> st;
	while (1)
	{
		int a;
		cin >> a;
		st.push(a);
		if (a == 0)
			break;
	}

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
}