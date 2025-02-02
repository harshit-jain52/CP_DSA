#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef vector<vector<int>> vvi;

const int M = 1e9+7;
const int ALLSET = (1<<9)-1;

void insert(int num, vvi &trie)
{
    int node = 0;
    for (int i=8;i>=0;i--){
        int bit = (num >> i) & 1;
        if (!trie[node][bit]){
            trie.push_back(vector<int>(2));
            trie[node][bit] = trie.size() - 1;
        }
        node = trie[node][bit];
    }
}

int findMax(int num, vvi &trie){
    int res=0, node=0;
    int find=ALLSET^num;
    for(int i=8;i>=0;i--){
        int bit = (find>>i)&1;
        if(trie[node][bit]){
            res += (1<<i);
            node = trie[node][bit];
        }
        else node = trie[node][1^bit];
    }
    return res;
}

void solve(){
	int n; cin >> n;
	int ans=0, prefxor=0;
	vvi trie(1,vector<int>(2));

	insert(0,trie);
	for(int i=0;i<n;i++){
		int a; cin >> a;
		prefxor^=a;
		ans = max(ans,findMax(prefxor,trie));
		insert(prefxor,trie);
	}

	cout << ans << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}