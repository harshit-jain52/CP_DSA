#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e7;

ll arr[N];

void gen(int x, int a, int b, int c, int n){
	arr[0]=x;
	for(int i=1;i<n;i++) arr[i]=(a*arr[i-1]+b)%c;
}

int main()
{
	FASTIO
	int n,k; cin >> n >> k;
	int x,a,b,c; cin >> x >> a >> b >> c;

	gen(x,a,b,c,n);

	ll ans=0;
	deque<int>dq;
    for(int i=0;i<n;i++){
        while(!dq.empty() && arr[dq.back()]>arr[i]) dq.pop_back();
        dq.push_back(i);

        if(dq.front()<i-k+1) dq.pop_front();

        if(i>=k-1) ans ^= arr[dq.front()];
    }

	cout << ans << endl;
}