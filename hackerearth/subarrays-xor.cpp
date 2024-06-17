#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int k;
ll ans;
vector<vector<int>> trie;
vector<vector<int>> cnt;

void insert(int num){
	int node = 0;
	for(int i=20;i>=0;i--){
		int bit = (num>>i)&1;

		if(!trie[node][bit]){
			trie.push_back(vector<int>(2));
			cnt.push_back(vector<int>(2));
			trie[node][bit] = trie.size()-1;
		}
		cnt[node][bit]++;
		node = trie[node][bit];
	}
}

void numXOR(int num){
	int node = 0;
	for(int i=20;i>=0;i--){
		int x = (k>>i)&1;
		int bit = (num>>i)&1;
		if(x == 1){
			ans += cnt[node][bit];
			if(trie[node][1^bit]) node = trie[node][1^bit];
			else break;
		}
		else{
			if(trie[node][bit]) node = trie[node][bit];
			else break;
		}
	}
}

void solve(){
	int n; cin >> n >> k;

	ans = 0;
	trie.assign(1,vector<int>(2));
	cnt.assign(1,vector<int>(2));
	int prefxor=0;
	insert(0);

	for(int i=0;i<n;i++){
		int a; cin >> a;
		prefxor^=a;
		numXOR(prefxor);
		insert(prefxor);
	}

	cout << ans << endl;
}

int main()
{
	FASTIO
	int t; cin >> t;
	while(t--) solve();
}

// https://www.hackerearth.com/problem/algorithm/subarrays-xor/