#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int a[n], ct = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                ct++;
        }
    }

    bool isEven = ct % 2 == 0;

    int m;
    cin >> m;

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int num = (r - l + 1) / 2;

        if (num % 2 == 1)
            isEven = !isEven;

        if (isEven)
            cout << "even";
        else
            cout << "odd";

        cout << endl;
    }
}