/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/a-needle-in-the-haystack-1/
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, alpha[26];
    string P, S;

    cin >> T;

    while (T--)
    {
        cin >> P >> S;

        for (i = 0; i < 26; i++)
        {
            alpha[i] = 0;
        }

        for (i = 0; i < S.size(); i++)
        {
            alpha[S[i] - 'a']++;
        }

        for (i = 0; i < P.size(); i++)
        {
            if (alpha[P[i] - 'a']-- <= 0)
            {
                break;
            }
        }

        if (i == P.size())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}