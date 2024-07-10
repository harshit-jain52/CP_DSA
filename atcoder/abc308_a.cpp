#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int s[8];
	bool flag = true;

	for(int i=0;i<8;i++){
		cin >> s[i];
		if(s[i]<100 || s[i]>675 || s[i]%25 != 0){
			flag = false;
		}
	}

	for(int i=1;i<8;i++){
		if(s[i]<s[i-1]) flag = false;
	}

	if(flag) cout << "Yes\n";
	else cout << "No\n";
}