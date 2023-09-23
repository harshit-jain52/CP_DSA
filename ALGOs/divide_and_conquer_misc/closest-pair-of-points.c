#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct p
{
    int x;
    int y;
} point;

// comparator functions
int compareX(const void *a, const void *b)
{
    point *p1 = (point *)a, *p2 = (point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b)
{
    point *p1 = (point *)a, *p2 = (point *)b;
    return (p1->y - p2->y);
}

float dist(point p1, point p2)
{
    return sqrtf((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}

float bruteForce(point P[], int n)
{
    float d = FLT_MAX;
    for (int i = 1; i < n; i++)
    {
        d = min(d, dist(P[i], P[i - 1]));
    }

    return d;
}

float stripClosest(point strip[], int size, float d)
{
    float ans = d;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < ans; j++)
        {
            ans = min(ans, dist(strip[i], strip[j]));
        }
    }

    return ans;
}

float closestPair(point Px[], point Py[], int n)
{
    if (n <= 2)
        return bruteForce(Px, n);

    int mid = n / 2;
    point midPoint = Px[mid]; // imaginary line passes through midPoint

    point *Pyl = (point *)malloc(mid * sizeof(point));
    point *Pyr = (point *)malloc((n - mid) * sizeof(point));

    int li = 0, ri = 0;
    for (int i = 0; i < n; i++)
    {
        if ((Py[i].x < midPoint.x || (Py[i].x == midPoint.x && Py[i].y < midPoint.y)) && li < mid)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }

    float dl = closestPair(Px, Pyl, mid);
    float dr = closestPair(Px + mid, Pyr, n - mid);

    free(Pyl);
    free(Pyr);

    float d = min(dl, dr);

    point *strip = (point *)malloc(n * sizeof(point));

    // strip contains points (sorted acc to y-coord) less than d units away from imaginary line
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(Py[i].x - midPoint.x) < d)
        {
            strip[j] = Py[i];
            j++;
        }
    }

    // candidate pts can only lie in the 2 neighbouring boxes of size dxd
    return min(d, stripClosest(strip, j, d));

    free(strip);
}

int main()
{
    point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);

    point *Px = (point *)malloc(n * sizeof(point));
    point *Py = (point *)malloc(n * sizeof(point));

    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    qsort(Px, n, sizeof(point), compareX); // sort points acc to x-coordinate
    qsort(Py, n, sizeof(point), compareX); // sort points acc to y-coordinate

    float minDist = closestPair(Px, Py, n);
    
    free(Px);
    free(Py);

    printf("\n%f\n",minDist);
}

// O(NlogN)