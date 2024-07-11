#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e4+4;
const int INF = 1e7;

int nxt[N];
vector<int>seg[4*N];

vector<int>merge(vector<int> &a, vector<int> &b)
{
    int n=a.size(),m=b.size();
    int i=0,j=0;
    vector<int>res;
    while (i<n && j<m)
    {
        if (a[i]<b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }

    while (i<n) res.push_back(a[i++]);
    while (j<m) res.push_back(b[j++]);

    return res;
}


void build(int id, int l, int r){
	if(l>r) return;
	if(l==r){
		seg[id] = vector<int>{nxt[l]};
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

int query(int id, int l, int r, int lq, int rq, int x){
	if(l>r || l>rq || lq>r) return 0;

	if(l>=lq && r<=rq){
		return (seg[id].end() - lower_bound(seg[id].begin(),seg[id].end(),x));
	}

	int mid = (l+r)/2;
	return (query(id<<1,l,mid,lq,rq,x)+query(id<<1|1,mid+1,r,lq,rq,x));
}

int main()
{
	FASTIO
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	map<int,int>mp;
	for(int i=n-1;i>=0;i--){
		if(mp.find(a[i])==mp.end()) nxt[i]=INF;
		else nxt[i]=mp[a[i]];

		mp[a[i]]=i;
	}

	build(1,0,n-1);

	int q; cin >> q;
	while(q--){
		int i,j; cin >> i >> j;
		cout << query(1,0,n-1,i-1,j-1,j) << endl;
	}
}