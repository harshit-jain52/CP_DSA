#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;
const int N = 1e5+5;

int idx[N];
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
		seg[id] = vector<int>{idx[l]};
		return;
	}

	int mid = (l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	seg[id]=merge(seg[id<<1],seg[id<<1|1]);
}

int query(int id, int l, int r, int lq, int rq, int k){
	if(l==r) return seg[id][0];

	int ct = upper_bound(seg[id<<1].begin(),seg[id<<1].end(),rq) - lower_bound(seg[id<<1].begin(),seg[id<<1].end(),lq);
	int mid = (l+r)/2;

	if(ct>=k) return query(id<<1,l,mid,lq,rq,k);
	else return query(id<<1|1,mid+1,r,lq,rq,k-ct); 
}

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	int a[n];
	vector<pii>nums(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		nums[i]=make_pair(a[i],i);
	}

	sort(nums.begin(),nums.end());
	for(int i=0;i<n;i++) idx[i]=nums[i].S;

	build(1,0,n-1);
	
	while(m--){
		int i,j,k; cin >> i >> j >> k;
		cout << a[query(1,0,n-1,i-1,j-1,k)] << endl;
	}
}