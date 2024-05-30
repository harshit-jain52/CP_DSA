#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int mex(set<int> st)
{
    int num = 0;
    for (int i : st)
        if (i == num)
            num++;
    return num;
}

void solve()
{
    int n;
    cin >> n;
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        z ^= (x % 4);
    }

    if (z)
        cout << "first";
    else
        cout << "second";
    cout << endl;
}

int main()
{
    FASTIO
    // int g[1000];
    // g[0]=0;
    // for(int i=1;i<1000;i++){
    //     set<int>tmp;
    //     if(i>=1) tmp.insert(g[i-1]);
    //     if(i>=2) tmp.insert(g[i-2]);
    //     if(i>=3) tmp.insert(g[i-3]);
    //     g[i]=mex(tmp);
    //     cout << i << " "<<g[i]<<endl;
    // }

    // found: grundy number: g[i]=i%4

    int t;
    cin >> t;
    while (t--)
        solve();
}