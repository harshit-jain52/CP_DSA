#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;
 
int arr[N];
vector<int> seg[4*N];
 
vector<int> merge(vector<int> &a, vector<int> &b){
	int n=a.size(),m=b.size();
	int i=0,j=0;
 
	vector<int>res;
	while(i<n && j<m){
		if(a[i]<b[j]) res.push_back(a[i++]);
		else res.push_back(b[j++]);
	}
 
	while(i<n) res.push_back(a[i++]);
	while(j<m) res.push_back(b[j++]);
	return res;
}
 
void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		vector<int>tmp{arr[l]};
		seg[id]=tmp;
		return;
	}
 
	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id] = merge(seg[id<<1],seg[id<<1|1]);
}
 
int query(int id, int l, int r, int lq, int rq, int c, int d){
	if(l>r || l>rq || lq>r) return 0;
	if(lq<=l && rq>=r) return (upper_bound(seg[id].begin(),seg[id].end(),d)-lower_bound(seg[id].begin(),seg[id].end(),c));
 
	int mid = (l+r)/2;
	return (query(id<<1,l,mid,lq,rq,c,d) + query(id<<1|1,mid+1,r,lq,rq,c,d));
}
 
int main()
{
	FASTIO
	int n,q; cin >> n >> q;
	for(int i=0;i<n;i++) cin >> arr[i];
 
	build(1,0,n-1);
 
	while(q--){
		int a,b,c,d; cin >> a >> b >> c >> d;
		cout << query(1,0,n-1,a-1,b-1,c,d) << endl;
	}
}