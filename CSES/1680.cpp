#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;

const int N = 1e5+5;
vector<int>g[N];
int n;

int dp[N];
int dp2[N];

bool dfs2(int v){
	if(v==n) return true;
	if(dp2[v]!=-1) return dp2[v];

	bool ans  = false;
	for(auto it: g[v]){
		ans |= dfs2(it);
	}

	return dp2[v]=ans;
}

int dfs(int v){
	if(v==n) return 1;
	if(dp[v]!=-1) return dp[v];

	int ans = 0;
	for(auto it: g[v]){
		if(dfs2(it)){
			ans = max(ans,1+dfs(it));
		}
	}
	return dp[v] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp,-1,sizeof(dp)); memset(dp2,-1,sizeof(dp2));
	int m;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	if(!dfs2(1)) cout << "IMPOSSIBLE";
	else{
		int maxnum = dfs(1);
		cout << maxnum<< endl;

		vector<int>ans;
		int curr = 1, num = maxnum;
		while(num>1){
			ans.push_back(curr);
			num--;
			for(int c:g[curr]){
				if(dfs(c)==num){
					curr = c;
					break;
				}
			}
		}
		ans.push_back(n);

		for(int it: ans){
			cout << it << " ";
		}
	}

}