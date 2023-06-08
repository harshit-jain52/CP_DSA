#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    vector<int> as(26), at(26);
    int i, j;
    cin >> s >> t;

    for (i = 0; i < s.size(); i++)
    {
        as[s[i] - 'a']++;
    }

    for (i = 0; i < t.size(); i++)
    {
        at[t[i] - 'a']++;
    }

    int flag = 1;
    for (i = 0; i < 26; i++)
    {
        if (as[i] < at[i])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        int automaton = 0;
        for (i = 0; i < 26; i++)
        {
            if (as[i] > at[i])
            {
                automaton = 1;
                break;
            }
        }

        for (i = 0, j = 0; i < s.size() && j < t.size(); i++)
        {
            if (s[i] == t[j])
            {
                j++;
            }
        }
        int array = !(j == t.size());

        if (automaton && array)
        {
            cout << "both";
        }
        else if (automaton)
        {
            cout << "automaton";
        }
        else
        {
            cout << "array";
        }
    }
    else
    {
        cout << "need tree";
    }
}