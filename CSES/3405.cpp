#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int N = 1e7;

int arr[N];

void gen(int x, int a, int b, int c, int n){
	arr[0]=x;
	for(int i=1;i<n;i++) arr[i]=(a*1LL*arr[i-1]+b)%c;
}

struct window{
	stack<pii> st1,st2;

	int query(){
		int val1 = st1.empty() ? 0 : st1.top().S;
		int val2 = st2.empty() ? 0 : st2.top().S;
		return val1 | val2;
	}

	void push(int val){
		int curr = st1.empty() ? 0 : st1.top().S;
		st1.push({val,val|curr});
	}

	void pop(){
		if(st2.empty()){
			while(!st1.empty()){
				int curr = st2.empty() ? 0 : st2.top().S;
				st2.push({st1.top().F, st1.top().F | curr});
				st1.pop();
			}
		}
		st2.pop();
	}
};


int main()
{
	FASTIO
	int n,k; cin >> n >> k;
	int x,a,b,c; cin >> x >> a >> b >> c;

	gen(x,a,b,c,n);

	window w;
	int ans = 0;

	for(int i=0;i<n;++i){
		w.push(arr[i]);
		if(i>=k-1){
			ans ^= w.query();
			w.pop();
		}
	}

	cout << ans;
}