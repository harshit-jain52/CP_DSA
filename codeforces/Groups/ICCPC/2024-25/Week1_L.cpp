#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	string s; cin >> s;
	int n = s.size();
	int tota=0,totb=0;
	for(int i=0;i<n;i++){
		tota += (s[i]=='A');
		totb += (s[i]=='B');
	}

	if((tota&1) || (totb&1)){
		cout << "NO";
		return 0;
	}

	int head=-1,tail=0;
	int tmpa=0,tmpb=0;
	while(tail<n){
		while(head+1<n && tmpa+(s[head+1]=='A')<=tota/2 && tmpb+(s[head+1]=='B')<=totb/2){
			head++;
			tmpa+=(s[head]=='A');
			tmpb+=(s[head]=='B');
		}

		if(tmpa==tota/2 && tmpb==totb/2){
			cout << "YES\n";
			cout << tail+1 << " " << head+2;
			return 0;
		}
		if(head>=tail){
			tmpa-=(s[tail]=='A');
			tmpb-=(s[tail]=='B');
			tail++;
		}
		else{
			tail++;
			head=tail-1;
		}
	}

	cout << "NO";
}