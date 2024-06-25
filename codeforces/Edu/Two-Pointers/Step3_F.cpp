#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,m;
	cin >> n >> m;

	string s; cin >> s;

	vector<int>card(26,0);
	vector<int>ct(26,0);
	for(int i=0;i<m;i++){
		char c; cin >> c;
		card[c-'a']++;
	}

	ll num = 0;
	int head=-1,tail=0;

	while(tail<n){
		while(head+1<n && ct[s[head+1]-'a']+1<=card[s[head+1]-'a']){
			head++;
			ct[s[head]-'a']++;
		}
		num += (head-tail+1);

		if(head>=tail){
			ct[s[tail]-'a']--;
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	cout << num;
}