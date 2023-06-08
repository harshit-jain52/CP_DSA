#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int flag;
    int count = 0;
    int len = s.length();
    char store[len - 2];

    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            flag = 1;

            for (int j = 0; j < count; j++)
            {

                if (s[i] == store[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                store[count] = s[i];
                count++;
            }
        }
    }

    cout << count;

    return 0;
}