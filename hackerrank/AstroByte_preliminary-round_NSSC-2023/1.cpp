#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;

            if (!st.empty() && st.top() != ch)
                st.pop();
            else
                st.push(ch);
        }
        cout << st.size() << endl;
    }
}