#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void sum_of_digits(string s)
{
    if (s.size() == 1)
    {
        return;
    }

    cnt++;
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum += (s[i] - '0');
    }

    sum_of_digits(to_string(sum));

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    sum_of_digits(str);

    cout << cnt;
}