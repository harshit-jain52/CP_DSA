#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

int to[N];
bool recur_stack[N], vis[N];
vector<int>ans(N,-1);

void dfs(int v, stack<int>&path){
	vis[v]=true;
	recur_stack[v]=true;
	path.push(v);

	int nxt = to[v];
	if(vis[nxt]){
		if(recur_stack[nxt]){
			queue<int>q;
			while(path.top()!=nxt){
				q.push(path.top());
				path.pop();
			}
			q.push(nxt);
			path.pop();

			int sz = q.size();
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

	if(ans[v]==-1) ans[v]=ans[nxt]+1;
	recur_stack[v]=false;
}

int main()
{
	FASTIO
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> to[i];

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			stack<int>path;
			dfs(i,path);
		}
	}

	ll tot=0;
	for(int i=1;i<=n;i++) tot += ans[i];
	cout << tot;
}