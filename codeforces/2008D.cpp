#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;
string s;
int p[N];
vector<int>ans;
vector<bool> recur_stack, vis;

void dfs(int v, stack<int>&path){
	vis[v]=true;
	recur_stack[v]=true;
	path.push(v);

	int nxt = p[v];
	if(vis[nxt]){
		if(recur_stack[nxt]){
			queue<int>q;
			int sz=0;
			while(path.top()!=nxt){
				q.push(path.top());
				sz += (s[path.top()]=='0');
				path.pop();
			}
			q.push(nxt);
			sz += (s[nxt]=='0');
			path.pop();

			while(!q.empty()){
				ans[q.front()]=sz;
				q.pop();
			}
		}
		else ans[v] = 1+ans[nxt];
	}
	else{
		dfs(nxt,path);
	}

	if(ans[v]==-1) ans[v]=ans[nxt]+(s[v]=='0');
	recur_stack[v]=false;
}

void solve(){
	int n; cin >> n;
	ans.assign(n+1,-1);
	recur_stack.assign(n+1,false);
	vis.assign(n+1,false);

	for(int i=1;i<=n;i++) cin >> p[i];
	cin >> s;
	s = "#" + s;

	// cout << s << endl;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			stack<int>path;
			dfs(i,path);
		}
	}

	for(int i=1;i<=n;i++) cout << ans[i] << " ";
	cout << endl;
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