#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

struct Node {
	ll val;
	Node *l, *r;

	Node(ll x) : val(x), l(nullptr), r(nullptr) {}
	Node(Node *l_, Node *r_) {
		l = l_, r = r_;
		val = 0;
		if (l) val += l->val;
		if (r) val += r->val;
	}
	Node(Node *cp) : val(cp->val), l(cp->l), r(cp->r) {}
};

ll arr[N];
Node *roots[N];

Node *build(int l, int r) {
	if (l == r) return new Node(arr[l]);
	int mid = (l + r) / 2;
	return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, int val, int pos, int l, int r) {
	if (l == r) return new Node(val);
	int mid = (l + r) / 2;
	if (pos > mid) return new Node(node->l, update(node->r, val, pos, mid + 1, r));
	else return new Node(update(node->l, val, pos, l, mid), node->r);
}

ll query(Node *node, int a, int b, int l, int r) {
	if (l > b || r < a) return 0;
	if (l >= a && r <= b) return node->val;
	int mid = (l + r) / 2;
	return query(node->l, a, b, l, mid) + query(node->r, a, b, mid + 1, r);
}

int main()
{
	FASTIO
	int n,q; cin >> n >> q;
	for(int i=0;i<n;i++) cin >> arr[i];

	int ct=0;
	roots[ct] = build(0,n-1);

	while(q--){
		int tp; cin >> tp;
		if(tp==1){
			int k,a,x; cin >> k >> a >> x;
			roots[k-1] = update(roots[k-1], x, a-1, 0, n-1);
		}
		else if(tp==2){
			int k,a,b; cin >> k >> a >> b;
			cout << query(roots[k-1],a-1,b-1,0,n-1) << endl;
		}
		else{
			int k; cin >> k;
			roots[++ct] = roots[k-1];
		}
	}
}