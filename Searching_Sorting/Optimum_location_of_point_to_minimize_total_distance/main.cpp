#include <bits/stdc++.h>
#define sq(x) ((x) * (x))
#define EPS 1e-6
#define N 5

using namespace std;

//  structure defining a point
struct point {
    int x, y;
    point() {}
    point(int x, int y)
        : x(x)
        , y(y)
    {
    }
};

//  structure defining a line of ax + by + c = 0 form
struct line {
    int a, b, c;
    line(int a, int b, int c)
        : a(a)
        , b(b)
        , c(c)
    {
    }
};

int **points;

//  method to get distance of point (x, y) from point p
double dist(double x, double y, point p)
{
    return sqrt(sq(x - p.x) + sq(y - p.y));
}

/*  Utility method to compute total distance all points
    when choose point on given line has x-coordinate
    value as X   */
double compute(point p[], int n, line l, double X)
{
    double res = 0;

    //  calculating Y of chosen point by line equation
    double Y = -1 * (l.c + l.a * X) / l.b;
    for (int i = 0; i < n; i++)
        res += dist(X, Y, p[i]);

    return res;
}

//  Utility method to find minimum total distance
double findOptimumCostUtil(point p[], int n, line l)
{
    double low = -1e6;
    double high = 1e6;

    // loop until difference between low and high
    // become less than EPS
    while ((high - low) > EPS) {
        // mid1 and mid2 are representative x co-ordiantes
        // of search space
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        //
        double dist1 = compute(p, n, l, mid1);
        double dist2 = compute(p, n, l, mid2);

        // if mid2 point gives more total distance,
        // skip third part
        if (dist1 < dist2)
            high = mid2;

        // if mid1 point gives more total distance,
        // skip first part
        else
            low = mid1;
    }

    // compute optimum distance cost by sending average
    // of low and high as X
    return compute(p, n, l, (low + high) / 2);
}

//  method to find optimum cost
double findOptimumCost(int **points, line l)
{
    point p[N];

    //  converting 2D array input to point array
    for (int i = 0; i < N; i++)
        p[i] = point(points[i][0], points[i][1]);

    return findOptimumCostUtil(p, N, l);
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    line l(x, y, z);
    points = (int **)malloc(N * sizeof(int *));
    for(int i = 0; i < N; i++) {
        points[i] = (int *)malloc(2 * sizeof(int));
        for(int j = 0; j < 2; j++)
            cin >> points[i][j];
    }
    cout << findOptimumCost(points, l) << endl;
    free(points);
    return 0;
}
