#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,r; cin >> n >> r;
	int d[n];
	for(int i=0;i<n;i++) cin >> d[i];

	int head=-1,tail=0;
	ll ct = 0;

	while(tail<n){
		while(head+1<n && d[head+1]-d[tail]<=r) head++;
		ct += (n-1-head);

		if(head>=tail) tail++;
		else{
			tail++;
			head = tail-1;
		}
	}

	cout << ct;
}