#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        int ct = 0;
        bool right = false;

        for (int i = 0; i < 2 * n; i++)
        {
            if (s[i] == '(')
            {
                if (right == true)
                    ct++;

                right = false;
                st.push('(');
            }
            else
            {
                right = true;
                st.pop();
            }
        }

        cout << n - ct << endl;
    }
}