#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; ll a,b;
	cin >> n >> a >> b;
	string s; cin >> s;

	a = min(a,2*b);
	
	int l=0,r=0;
	for(int i=0;i<2*n;i++){
		l += (s[i]=='(');
		r += (s[i]==')');
	}

	ll tot = 0;
	if(r>l){
		int extra = (r-l)/2;
		tot += b*extra;
		int ct = 0;
		stack<int>st;
		for(int i=0;i<2*n;i++){
			if(s[i]==')'){
				if(st.empty()){
					ct++;
					st.push(1);
				}
				else st.pop();
			}
			else st.push(1);
		}
		tot += a*(ct-extra);
	}
	else{
		int extra = (l-r)/2;
		tot += b*extra;
		int ct = 0;
		stack<int>st;

		for(int i=2*n-1;i>=0;i--){
			if(s[i]=='('){
				if(st.empty()){
					ct++;
					st.push(1);
				}
				else st.pop();
			}
			else st.push(1);
		}

		tot += a*(ct-extra);
	}

	cout << tot;
}