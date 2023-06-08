/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/pair-sums/
*/

#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
long int A[2*M];

int main()
{
    int N, K, i, temp;

    cin >> N >> K;

    for (i = 1; i <= N; i++)
    {
        cin >> temp;
        A[temp]++;
    }

    for (i = 1; i <= K / 2; i++)
    {
        if (A[i]-- > 0 && A[K - i]-- > 0)
        {
            break;
        }
    }

    if (i == K / 2 + 1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}