#include <bits/stdc++.h>
using namespace std;

int main()
{
    string raw, result = "";
    int i;
    char ch;

    cin >> raw;
    for (i = 0; i < raw.size(); i++)
    {
        ch = tolower(raw[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
        {
            continue;
        }

        result.push_back('.');
        result.push_back(ch);
    }

    cout << result;
}