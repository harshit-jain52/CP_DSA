#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; ll p;
	cin >> n >> p;
	vector<ll>vec;
	ll a[n], tot=0;

	for(int i=0;i<n;i++){
		cin >> a[i];
		vec.push_back(a[i]);
		tot += a[i];
	}

	ll base = p/tot;
	p = p%tot;

	if(p==0){
		cout << 1 << " "<<n*base;
		return 0;
	}

	for(int i=0;i<n;i++) vec.push_back(a[i]);

	int len=n+1,start=0;
	int head=-1,tail=0;
	ll curr=0;

	while(tail<2*n){
		while(head+1<2*n && curr+vec[head+1]<p){
			head++;
			curr += vec[head];
		}
		if(head!=2*n-1){
			int tmp = head-tail+2;
			if(tmp<len){
				len = tmp;
				start = tail;
			}
		}

		if(head>=tail){
			curr -= vec[tail];
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	if(start>=n) start = n-start;
	cout <<start+1 <<" "<< base*n+len;
}