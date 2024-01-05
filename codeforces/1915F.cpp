#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void conquer(int l, int r, vector<pair<int,int>>&vec, ll &ct){
	int m = (l+r)/2;
	int n1 = m-l+1, n2 = r-m;
	vector<pair<int,int>>left(vec.begin()+l,vec.begin()+m+1);
	vector<pair<int,int>>right(vec.begin()+m+1,vec.begin()+r+1);
	left.push_back({INT_MIN,INT_MIN});
	right.push_back({INT_MIN,INT_MIN});

	int i=0,j=0,k=l;

	while(k<=r){
		if(left[i].second > right[j].second){
			ct += (n2-j);
			vec[k++] = left[i++];
		}
		else{
			vec[k++] = right[j++];
		}
	}
}

void divide(int l, int r, vector<pair<int,int>>&vec, ll &ct){
	if(l>=r) return;
	int mid = (l+r)/2;
	divide(l,mid,vec,ct);
	divide(mid+1,r,vec,ct);
	conquer(l,r,vec,ct);
}

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>>v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;
	}

	ll ct=0;
	sort(v.begin(),v.end()); // sort by a
	
	// for(auto it: v) cout << it. first<< " "<< it.second<< endl;
	divide(0,n-1,v,ct);
	cout << ct;
	// for(auto it: v) cout << it. first<< " "<< it.second<< endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
}