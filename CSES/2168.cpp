#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

typedef struct
{
    int x;
    int y;
    int idx;
} range;

vector<int> bigger(N, 0);
vector<int> smaller(N, 0);

void mergeSortbyX(range arr[], int l, int r);
void mergebyX(range arr[], int l, int m, int r);
void divide(range arr[], int l, int r);
void conquer(range arr[], int l, int m, int r);

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        int x, y;
        cin >> x >> y;
        cout << 0 << endl
             << 0;

        return 0;
    }

    range r[n];
    for (int i = 0; i < n; i++)
    {
        r[i].idx = i;
        cin >> r[i].x >> r[i].y;
    }

    mergeSortbyX(r, 0, n - 1);
    divide(r, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << bigger[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << smaller[i] << " ";
    }
}

void mergeSortbyX(range arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSortbyX(arr, l, mid);
    mergeSortbyX(arr, mid + 1, r);

    mergebyX(arr, l, mid, r);
}

void mergebyX(range arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int i, j, k;

    range left[n1 + 1];
    range right[n2 + 1];

    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    left[n1].x = right[n2].x = left[n1].y = right[n2].y = 1e9 + 10;
    left[n1].idx = right[n2].idx = -1;

    i = 0;
    j = 0;
    k = l;

    while (k <= r)
    {
        if (left[i].x == right[j].x)
        {
            if (left[i].y < right[j].y)
            {
                arr[k] = right[j];
                j++;
            }
            else
            {
                arr[k] = left[i];
                i++;
            }
        }
        else if (left[i].x < right[j].x)
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
}

void divide(range arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    divide(arr, l, mid);
    divide(arr, mid + 1, r);

    conquer(arr, l, mid, r);
}

void conquer(range arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int i, j;

    range low[n1 + 1];
    range high[n2 + 1];

    int lowmaxy = -1, highminy = 1e9 + 10;
    for (i = 0; i < n1; i++)
    {
        low[i] = arr[l + i];
        lowmaxy = max(lowmaxy, low[i].y);
    }

    for (j = 0; j < n2; j++)
    {
        high[j] = arr[m + 1 + j];
        highminy = min(highminy, high[j].y);
    }

    for (i = 0; i < n1; i++)
    {
        if (low[i].y >= highminy)
            bigger[low[i].idx] = 1;
    }

    for (j = 0; j < n2; j++)
    {
        if (high[j].y <= lowmaxy)
            smaller[high[j].idx] = 1;
    }
}
