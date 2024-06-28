#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

int main()
{
	FASTIO
	int n; cin >> n;
	int p[n], order[n+1];

	for(int i=0;i<n;i++){
	 	cin >> p[i];
	 	order[p[i]]=i;
	}


	string s; cin >> s;
	s = "#"+s;

	int start = p[0];
	int num1=1,num2=1;

	auto next = [&](int idx)->int{
		idx++;
		if(idx==n+1) idx=1;
		return idx;
	};

	auto prev = [&](int idx)->int{
		idx--;
		if(idx==0) idx=n;
		return idx;
	};

	if(s[start]!='L'){
		int i = next(start);
		while(i!=start){
			if(order[i]>order[next(i)] && s[next(i)]=='L'){
				num1 =0;
				break;
			}
			if(s[i]=='?' && order[i]>order[prev(i)]) num1 = (2LL*num1)%M;
			i = next(i);
		}
	}

	if(s[start]!='R'){
		int i = prev(start);
		while(i!=start){
			if(order[i]>order[prev(i)] && s[prev(i)]=='R'){
				num2 =0;
				break;
			}
			if(s[i]=='?' && order[i]>order[next(i)]) num2 = (2LL*num2)%M;
			i = prev(i);
		}
	}

	int ans = 0;
	if(s[start]!='L') ans+=num1;
	if(s[start]!='R') ans+=num2;
	ans %= M;

	cout << ans;
}