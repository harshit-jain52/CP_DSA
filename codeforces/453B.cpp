#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int INF = 1e7;
const int N = 101;
const int LOG = 16; // no. of primes till 58

int dp[N][1<<LOG], prec[60];
int mp[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
pair<int,int> nxt[N][1<<LOG];

void precompute(){
	for(int num=1;num<=58;num++){
		prec[num]=0;
		for(int p=0;p<16;p++) if(num%mp[p]==0) prec[num]+=(1<<p);
	}
}

int main()
{
	FASTIO
	precompute();

	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	for(int mask=0; mask<(1<<LOG); mask++) dp[n][mask]=0;

	for(int id=n-1;id>=0;id--){
		for(int mask=0;mask<(1<<LOG);mask++){
			dp[id][mask] = INF;
			for(int num=1;num<=58;num++){
				if((prec[num]&mask)==0){
					int nmask = prec[num]|mask;
					int calc = abs(a[id]-num)+dp[id+1][nmask];
					if(calc<dp[id][mask]){
						dp[id][mask] = calc;
						nxt[id][mask] = make_pair(num,nmask);
					}
				}
			}
		}
	}

	int mask = 0;
	for(int i=0;i<n;i++){
		cout << nxt[i][mask].first<<" ";
		mask = nxt[i][mask].second;
	}
}