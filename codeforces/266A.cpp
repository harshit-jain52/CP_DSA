#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i = 0, count, sum = 0;
    char temp;
    string s;

    cin >> n >> s;

    while (i < n)
    {
        temp = s[i];
        i++;
        count = 0;
        while (s[i] == temp)
        {
            i++;
            count++;
        }
        sum += count;
    }

    cout << sum;

    return 0;
}