#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, len;
    string word;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> word;

        len = 0;
        for (int i = 0; word[i] != '\0'; i++)
        {
            len += 1;
        }

        if (len > 10)
        {
            cout << word[0] << (len - 2) << word[len - 1] << endl;
        }
        else
        {
            cout << word << endl;
        }
    }

    return 0;
}