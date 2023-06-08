/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/little-jhool-and-the-magical-jewels/
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, ruby[4], min;
    string S;

    cin >> T;

    while (T--)
    {
        cin >> S;

        for (i = 0; i < 4; i++)
        {
            ruby[i] = 0;
        }

        for (i = 0; i < S.length(); i++)
        {
            switch (S[i])
            {
            case 'r':
                ruby[0]++;
                break;
            case 'u':
                ruby[1]++;
                break;
            case 'b':
                ruby[2]++;
                break;
            case 'y':
                ruby[3]++;
            default:
                break;
            }
        }

        min = 25;

        for (i = 0; i < 4; i++)
        {
            if (ruby[i] < min)
            {
                min = ruby[i];
            }
        }

        cout << min << endl;
    }
}