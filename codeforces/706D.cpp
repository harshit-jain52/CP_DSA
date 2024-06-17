#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int ALLSET = (1LL<<31)-1;

vector<vector<int>> trie(1, vector<int>(2));
vector<vector<int>> cnt(1,vector<int>(2));

void insert(int num){
	int node = 0;
	for(int i=30;i>=0;i--){
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

void remove(int num){
	int node = 0;
	for(int i=30;i>=0;i--){
		int bit = (num>>i)&1;
		cnt[node][bit]--;
		node = trie[node][bit];
	}
}

int maxXOR(int num){
	int req = ALLSET^num;
	int ans = 0, node = 0;
	for(int i=30;i>=0;i--){
		int bit = (req>>i)&1;
		if(cnt[node][bit]>0){
			ans += (1<<i);
			node = trie[node][bit];
		}
		else node = trie[node][1^bit];
	}

	return ans;
}

int main()
{
	FASTIO
	int q; cin >> q;
	insert(0);
	while(q--){
		char c; int num;
		cin >> c >> num;

		switch(c){
            case '+':{
                insert(num);
                break;
            }
            case '-':{
                remove(num);
                break;
            }
            default:{
                cout << maxXOR(num)<<endl;	
            }
	    }
	}
}