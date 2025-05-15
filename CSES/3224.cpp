#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;

struct window{
	map<int,int> ct;
	map<int,set<int>>mp;

	int query(){
		auto it = mp.end();
		it--;
		auto &pp = *it;
		return *(pp.S.begin());
	}

	void push(int val){
		int f = ++ct[val];
		mp[f].insert(val);
		if(mp.find(f-1)!=mp.end()){
			if(mp[f-1].find(val)!=mp[f-1].end()){
				mp[f-1].erase(val);
				if(mp[f-1].empty()) mp.erase(f-1);
			}
		}
	}

	void pop(int val){
		int f = --ct[val];
		mp[f].insert(val);
		if(mp.find(f+1)!=mp.end()){
			if(mp[f+1].find(val)!=mp[f+1].end()){
				mp[f+1].erase(val);
				if(mp[f+1].empty()) mp.erase(f+1);
			}
		}
	}
};

int main()
{
	FASTIO
	int n,k; cin >> n >> k;

	int x[n];
	for(int i=0;i<n;i++) cin >> x[i];

	window w;
	for(int i=0;i<n;i++){
		w.push(x[i]);
		if(i>=k-1){
			cout << w.query() << " ";
			w.pop(x[i-k+1]);
		}
	}
}