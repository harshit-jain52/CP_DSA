#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e4+5;
const int IMAX = 1e6+10;

int block_sz;
int a[N];
int ct[IMAX];
int curr_ans=0;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {	
    	if(l/block_sz == other.l/block_sz) return r < other.r; 
        return l < other.l;
    }
};

void ins(int idx){
	ct[a[idx]]++;
	if(ct[a[idx]]==1) curr_ans++;
}

void ers(int idx){
	ct[a[idx]]--;
	if(ct[a[idx]]==0) curr_ans--;
}

int main()
{
	FASTIO
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	block_sz = sqrt(n);

	int q;
	cin >> q;
	vector<Query>queries(q);
	for(int i=0;i<q;i++){
		cin>>queries[i].l>>queries[i].r;
		queries[i].idx=i;
	}
	sort(queries.begin(), queries.end());

	int ans[q];
	int mo_r=0,mo_l=1;

	for(auto &qy: queries){
		while(mo_r < qy.r) ins(++mo_r);
		while(mo_l > qy.l) ins(--mo_l);
		while(mo_r > qy.r) ers(mo_r--);
		while(mo_l < qy.l) ers(mo_l++);

		ans[qy.idx]=curr_ans;
	}

	for(int i=0;i<q;i++) cout << ans[i]<<endl;
}