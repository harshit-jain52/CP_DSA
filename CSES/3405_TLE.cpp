#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e7;

int arr[N];
int ct[30] = {0};

void gen(int x, int a, int b, int c, int n){
	arr[0]=x;
	for(int i=1;i<n;i++) arr[i]=(a*1LL*arr[i-1]+b)%c;
}

int main()
{
	FASTIO
	int n,k; cin >> n >> k;
	int x,a,b,c; cin >> x >> a >> b >> c;

	gen(x,a,b,c,n);

	int ans = 0;

	for(int i=0;i<n;++i){
		int num=0;
		for(int bit=0;bit<30;++bit){
			ct[bit] += (arr[i]>>bit)&1;
			if(i>=k-1){
				if(ct[bit]) num += (1 << bit);
				ct[bit] -= (arr[i-k+1]>>bit)&1;
			}
		}
		ans ^= num;
	}

	cout << ans;
}