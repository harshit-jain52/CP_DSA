#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	string s,t;
	cin >> s >> t;

	vector<vector<bool>>g(26,vector<bool>(26,false));
	vector<int>nxt(26,-1);
	for(int i=0;i<n;i++) g[s[i]-'a'][t[i]-'a']=true;

	int ans = 0;
	int selfloops = 0;
	for(int i=0;i<26;i++){
		int ct=0;
		for(int j=0;j<26;j++){
			if(g[i][j]){
				ct++;
				if(i!=j){
					ans++;
					nxt[i]=j;
				}
				else selfloops++;
			}
		}
		if(ct>=2){
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int>vis(26,0);
	int timer=0;
	vector<vector<int>>cyc;
	for(int i=0;i<26;i++){
		if(vis[i]!=0) continue;
		int start = ++timer;
		int j = i;
		vis[j]=start;
		while(nxt[j]!=-1){
			j = nxt[j];
			if(vis[j]){
				if(vis[j]>=start){
					int k=i;
					while(k!=j) k=nxt[k];
					vector<int>c;
					c.push_back(k);
					k=nxt[k];
					while(k!=j){
						c.push_back(k);
						k=nxt[k];
					}
					cyc.push_back(c);
				}
				break;
			}
			vis[j] = ++timer;
		}
	}

	int cyclen=0;
	vector<int>incyc(26,0);
	vector<bool>cancel(cyc.size()+1,false);
	for(int i=0;i<cyc.size();i++){
		for(int j: cyc[i]){
			cyclen++;
			incyc[j]=i+1;
		}
	}

	if(cyclen>0 && cyclen+selfloops==26){
		cout << -1 << endl;
		return 0;
	}

	ans += cyc.size();

	for(int i=0;i<26;i++){
		if(nxt[i]==-1 || incyc[i]!=0) continue;
		cancel[incyc[nxt[i]]]=true;
	}

	for(int i=1;i<=cyc.size();i++) ans -= cancel[i];

	cout << ans << endl;

}