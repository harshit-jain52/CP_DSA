#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

ll maxSubArray(vector<int> &nums)
{
    ll max_so_far = INT_MIN, max_ending_here = 0, i;

    for (i = 0; i < nums.size(); i++)
    {
        max_ending_here += nums[i];
        max_so_far = max(max_so_far, max_ending_here);
        if (max_ending_here < 0)
            max_ending_here = 0;
        
    }

    return max(0LL,max_so_far);
}

ll minSubArray(vector<int> &nums)
{
    ll min_so_far = INT_MAX, min_ending_here = 0, i;

    for (i = 0; i < nums.size(); i++)
    {
        min_ending_here += nums[i];
        min_so_far = min(min_so_far, min_ending_here);
        if (min_ending_here > 0)
            min_ending_here = 0;
        
    }

    return min(0LL,min_so_far);
}

int main()
{
	FASTIO
	int n; cin >> n;
	ll c; cin >> c;

	vector<int>a(n);
	ll tot = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		tot += a[i];
	}

	ll maxsub = maxSubArray(a);
	ll minsub = minSubArray(a);

	if(c<=0) cout << tot+(c-1)*minsub;
	else cout << tot + (c-1)*maxsub;
}