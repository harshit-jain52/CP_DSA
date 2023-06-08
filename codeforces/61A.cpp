#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3 = "";
    int i;

    cin >> s1 >> s2;

    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == s2[i])
        {
            s3 += '0';
        }
        else
        {
            s3 += '1';
        }
    }

    cout << s3;

    return 0;
}