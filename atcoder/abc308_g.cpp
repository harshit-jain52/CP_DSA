#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int q; cin >> q;

	map<int,int>mp;
	multiset<int>ms;

	while(q--){
		int tp; cin >> tp;
		if(tp==3){
			auto it = mp.begin();
			cout << (*it).first << endl;
		}
		else{
			int x; cin >> x;
			if(tp==1){
				if(ms.size()>0){
					auto it = ms.lower_bound(x);
					int y1=-1,y2=-1;
					if(it!=ms.end()){
						y1 = (*it);
						mp[x^y1]++;
					}
					if(it!=ms.begin()){
						it--;
						y2 = (*it);
						mp[x^y2]++;
						if(y1!=-1){
							mp[y1^y2]--;
							if(mp[y1^y2]==0) mp.erase(y1^y2);
						}
					}
				}
				ms.insert(x);
			}
			else{
				auto it = ms.find(x);
				auto tmp1 = it, tmp2=it;
				int y1=-1,y2=-1;

				tmp1++;
				if(tmp1!=ms.end()){
					y1 = (*tmp1);
					mp[x^y1]--;
					if(mp[x^y1]==0) mp.erase(x^y1);
				}
				if(tmp2 !=ms.begin()){
					tmp2--;
					y2 = (*tmp2);
					mp[x^y2]--;
					if(mp[x^y2]==0) mp.erase(x^y2);
					if(y1!=-1) mp[y1^y2]++;
				}

				ms.erase(it);
			}
		}
	}
}