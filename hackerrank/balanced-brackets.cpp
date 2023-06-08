#include <bits/stdc++.h>
using namespace std;

char match(char c)
{
    if (c == '{')
    {
        return '}';
    }
    else if (c == '(')
    {
        return ')';
    }
    else
    {
        return ']';
    }
}

string isBalanced(string s)
{
    stack<char> p;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            p.push(match(s[i]));
        }
        else
        {
            if (p.empty())
            {
                break;
            }
            else
            {
                if (s[i] == p.top())
                {
                    p.pop();
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (i == s.size() && p.empty())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    int n;
    cin >> n;

    string str;
    while (n--)
    {
        cin >> str;
        cout << isBalanced(str) << endl;
    }
}