#include <bits/stdc++.h>
using namespace std;

int day(int arr[], int limit)
{
    int i = 0, count = 0;

    if (limit == 0)
    {
        for (i = 6; i >= 0; i--)
        {
            if (arr[i] > 0)
            {
                return (i + 1);
            }
        }
    }

    for (i = 0; i < 7; i++)
    {
        count += arr[i];
        if (count >= limit)
        {
            return (i + 1);
        }
    }
}

int main()
{
    int n, week[7], i, pages = 0, week_count = 0;
    cin >> n;

    for (i = 0; i < 7; i++)
    {
        cin >> week[i];
        week_count += week[i];
    }

    cout << day(week, n % week_count);
}