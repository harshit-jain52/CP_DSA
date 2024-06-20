#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    // Sum of Min(S)
    ll dp1[n + 1],sum1=0; // dp1[i] = sum of min(S) of all subarrays S starting at i
    dp1[n] = 0;
    vector<int> nle(n, n);
    stack<int> st1;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st1.empty() && a[st1.top()] >= a[i]) st1.pop();
        if (!st1.empty()) nle[i] = st1.top();
        st1.push(i);
        dp1[i] = dp1[nle[i]] + a[i] * 1LL * (nle[i] - i);
        sum1+=dp1[i];
    }
    
    // Sum of Max(S)
    ll dp2[n + 1],sum2=0; // dp2[i] = sum of max(S) of all subarrays S starting at i
    dp2[n] = 0;
    vector<int> nge(n, n);
    stack<int> st2;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st2.empty() && a[st2.top()] <= a[i]) st2.pop();
        if (!st2.empty()) nge[i] = st2.top();
        st2.push(i);
        dp2[i] = dp2[nge[i]] + a[i] * 1LL * (nge[i] - i);
        sum2+=dp2[i];
    }
    
    cout << sum2-sum1;
}