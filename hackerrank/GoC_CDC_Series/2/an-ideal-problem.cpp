#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 1;
int hp[N];
vector<bool> isPrime(N, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            hp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> st;

    auto check = [&](int num) -> bool
    {
        while (num > 1)
        {
            int p = hp[num];
            if (st.find(p) != st.end())
                return false;
            while (num % p == 0)
                num /= p;
        }
        return true;
    };

    auto insert = [&](int num) -> void
    {
        while (num > 1)
        {
            int p = hp[num];
            st.insert(p);
            while (num % p == 0)
                num /= p;
        }
    };

    auto remove = [&](int num) -> void
    {
        while (num > 1)
        {
            int p = hp[num];
            st.erase(p);
            while (num % p == 0)
                num /= p;
        }
    };

    int tail = 0, head = -1;
    int ans = 1;
    while (tail < n)
    {
        while (head + 1 < n && check(a[head + 1]))
        {
            head++;
            insert(a[head]);
        }
        ans = max(ans, head - tail + 1);
        if (head >= tail)
        {
            remove(a[tail]);
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout << ans;
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}