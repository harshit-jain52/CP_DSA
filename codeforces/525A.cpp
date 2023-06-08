#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, buy = 0;
    string s;
    multiset<char> keys;
    multiset<char>::iterator it;
    cin >> n;
    cin >> s;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (i % 2 == 0)
        {
            keys.insert(s[i]);
        }
        else
        {
            it = keys.find(s[i] + 'a' - 'A');
            if (it == keys.end())
            {
                buy++;
                continue;
            }
            else
            {
                keys.erase(it);
            }
        }
    }

    cout << buy;
}