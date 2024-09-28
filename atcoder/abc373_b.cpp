#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	string s; cin >> s;
	int pos[26];

	for(int i=0;i<26;i++) pos[s[i]-'A']=i;

	int ans = 0;
	for(int i=1;i<26;i++) ans += abs(pos[i]-pos[i-1]);

	cout << ans;
}