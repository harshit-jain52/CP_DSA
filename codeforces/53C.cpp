#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
    }
    else
    {
        int i = 1, j = n;
        while (i <= j)
        {
            if (i == j)
            {
                cout << i;
            }
            else
            {
                cout << i << " " << j << " ";
            }

            i++;
            j--;
        }
    }
}