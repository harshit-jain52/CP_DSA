#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, temp = "";
    int i, j, temp_size;
    cin >> s;

    for (i = 0; i < s.size(); i++)
    {
        if (s[i] != '+')
        {
            temp.push_back(s[i]);
        }
    }

    temp_size = temp.size();
    for (i = 0; i < temp_size - 1; i++)
    {
        for (j = 0; j < temp_size - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                swap(temp[j], temp[j + 1]);
            }
        }
    }

    for (i = 0; i < temp_size - 1; i++)
    {
        cout << temp[i] << "+";
    }
    cout << temp[temp_size - 1];
}