#include <bits/stdc++.h>
using namespace std;

bool isPresent(string s, char c)
{
    int i, len = s.size();

    for (i = 0; i < len; i++)
    {
        if (s[i] == c)
            return 1;
    }

    return 0;
}

int main()
{
    string username, distinct = "";
    int i;

    cin >> username;

    for (i = 0; i < username.size(); i++)
    {
        if (!(isPresent(distinct, username[i])))
        {
            distinct.push_back(username[i]);
        }
    }

    if (distinct.size() % 2)
    {
        cout << "IGNORE HIM!";
    }
    else
    {
        cout << "CHAT WITH HER!";
    }

    return 0;
}