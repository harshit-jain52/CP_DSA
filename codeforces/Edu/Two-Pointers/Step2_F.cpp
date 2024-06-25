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
	int n; ll k;
	cin >> n >> k;
	ll a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	multiset<ll>ms;

	auto check = [&](ll num)->bool{
		if(ms.empty()) return true;
		auto it1 = ms.begin();
		if(abs((*it1)-num)>k) return false;
		auto it2 = ms.rbegin();
		if(abs((*it2)-num)>k) return false;
		return true;
	};

	int head=-1, tail=0;
	ll ct = 0;

	while(tail<n){
		while(head+1<n && check(a[head+1])){
			head++;
			ms.insert(a[head]);
		}
		ct += (head-tail+1);

		if(head>=tail){
			ms.erase(ms.find(a[tail]));
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	cout << ct;
}