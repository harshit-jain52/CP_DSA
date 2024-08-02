#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n1,n2,n3,n4;

	cin >> n1; vector<int>a1(n1);
	for(int i=0;i<n1;i++) cin >> a1[i];
	sort(a1.begin(),a1.end());

	cin >> n2; vector<int>a2(n2);
	for(int i=0;i<n2;i++) cin >> a2[i];
	sort(a2.begin(),a2.end());

	cin >> n3; vector<int>a3(n3);
	for(int i=0;i<n3;i++) cin >> a3[i];
	sort(a3.begin(),a3.end());

	cin >> n4; vector<int>a4(n4);
	for(int i=0;i<n4;i++) cin >> a4[i];
	sort(a4.begin(),a4.end());

	int cap=-1,shirt=-1,pant=-1,shoe=-1;
	int ans = INT_MAX;

	int i1=0,i2=0,i3=0,i4=0;

	auto findDiff = [&]()->int{
		int diff = INT_MIN;
		diff = max({diff,abs(a1[i1]-a2[i2]),abs(a1[i1]-a3[i3]),abs(a1[i1]-a4[i4])});
		diff = max({diff,abs(a2[i2]-a3[i3]),abs(a2[i2]-a4[i4])});
		diff = max(diff,abs(a3[i3]-a4[i4]));
		return diff;
	};

	while(i1<n1 && i2<n2 && i3<n3 && i4<n4){
		int curr = findDiff();
		if(curr<ans){
			ans = curr;
			cap=i1,shirt=i2,pant=i3,shoe=i4;
		}

		if(a1[i1] <= min({a2[i2],a3[i3],a4[i4]})) i1++;
		else if(a2[i2] <= min({a1[i1],a3[i3],a4[i4]})) i2++;
		else if(a3[i3] <= min({a1[i1],a2[i2],a4[i4]})) i3++;
		else if(a4[i4] <= min({a1[i1],a3[i3],a2[i2]})) i4++;
	}
	// cout << ans << endl;
	cout << a1[cap]<< " "<<a2[shirt]<<" "<<a3[pant]<<" "<<a4[shoe];

}