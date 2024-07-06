#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;
const int N = 14;
const ll INF = 1e15;
#define F first
#define S second

vector<vector<ll>>dist((1<<N),vector<ll>(N+2,INF));
int n;

pii Mask(string &s){
	int idx=-1;
	int ct = 0, mask=0;
	for(int i=0;i<=n+1;){
		if(s[i]=='.'){
			idx=i; i+=2;
		}
		else{
			if(s[i]=='B') mask += (1<<ct);
			i++;
			ct++;
		}
	}

	return make_pair(mask,idx);
}

string Stones(int mask, int idx){
	string s = "";
	int ct=0;
	for(int i=0;i<=n+1;){
		if(i==idx){
			s+="..";
			i+=2;
		}
		else{
			if((mask>>ct)&1) s += 'B';
			else s += 'W';
			i++; ct++;
		}
	}

	return s;
}


int main()
{
	FASTIO
	cin >> n;
	string s,t;
	cin >> s >> t;
	s+="..";
	t+="..";

	if(n==2){
		if(s==t) cout << 0;
		else cout << -1;
		return 0;
	}

	pii init = Mask(s);
	// cout << init.F << " "<<init.S<<endl;
	// cout << Stones(init.F,init.S) << endl;
	
	queue<pii>q;
	dist[init.F][init.S]=0;
	q.push(init);

	while(!q.empty()){
		auto cur = q.front();
		int mask = cur.F, idx = cur.S;
		q.pop();

		string str = Stones(mask,idx);
		for(int i=0;i<=n;i++){
			if(str[i]=='.' || str[i+1]=='.') continue;
			string tmp=str;
			swap(tmp[i],tmp[idx]);
			swap(tmp[i+1],tmp[idx+1]);
			pii nxt = Mask(tmp);
			if(dist[nxt.F][nxt.S]>dist[mask][idx]+1){
				dist[nxt.F][nxt.S]=dist[mask][idx]+1;
				q.push({nxt.F,nxt.S});
			}
		}
	}

	pii fin = Mask(t);
	ll ans = dist[fin.F][fin.S];
	cout << ((ans<INF)?ans:-1);
}