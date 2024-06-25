#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; ll c;
	cin >> n >> c;
	string s; cin >> s;

	int cta=0, ctb=0;ll rude=0;
	int head=-1,tail=0, len=0;

	while(tail<n){
		while(head+1<n && (s[head+1]!='b' || rude+cta<=c)){
			head++;
			if(s[head]=='a') cta++;
			if(s[head]=='b'){
				ctb++;
				rude += cta;
			}
		}
		len = max(len,head-tail+1);

		if(head>=tail){
			if(s[tail]=='a'){
				rude -= ctb;
				cta--;
			}
			if(s[tail]=='b') ctb--;
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	cout << len;
}