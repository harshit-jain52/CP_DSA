#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,k;
	cin >> n >> k;
	int num=0;
	
	while(num*(num+1)/2 <= k){
		num++;
	}
    num--;

    if(num!=0) cout << 2 << " ";
    for(int i=2;i<=num;i++){
    	cout << i+1 << " ";
    }

    int x = k - num*(num+1)/2;
    if(x!=0){
    	int tmp = (num+1)*(num+2)/2 - (x+1)*(x+2)/2;
    	cout << -tmp-1 << " ";
    }
    int start = num+1+ (x!=0);
    for(int i = start;i<=n;i++) cout << -1000 << " ";

    cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}