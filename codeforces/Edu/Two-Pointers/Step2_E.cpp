#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5;
int main()
{
	FASTIO
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	vector<int>ct(N+1,0);

	int head=-1,tail=0, uni=0;
	ll num = 0;

	while(tail<n){
		while(head+1<n && uni+(ct[a[head+1]]==0)<=k){
			head++;
			ct[a[head]]++;
			uni += (ct[a[head]]==1);
		}

		num += (head-tail+1);
		if(head>=tail){
			ct[a[tail]]--;
			uni -= (ct[a[tail]]==0);
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	cout << num;
}