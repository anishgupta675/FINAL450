#include <iostream>
using namespace std;

#define __INSERT_THRESH 5
#define __swap(x, y) (t = *(x), *(x) = *(y), *(y) = t)

int *a;

// Both sorted sub-arrays must be adjacent in 'a'
// 'an' is the length of the first sorted section in 'a'
// 'bn' is the length of the second sorted section in 'a'
static void merge(int* a, size_t an, size_t bn)
{
    int *b = a + an, *e = b + bn, *s, t;

    // Return right now if we're done
    if (an == 0 || bn == 0 || !(*b < *(b - 1)))
        return;

    // Do insertion sort to merge if size of sub-arrays are
    // small enough
    if (an < __INSERT_THRESH && an <= bn) {
        for (int *p = b, *v; p > a;
             p--) // Insert Sort A into B
            for (v = p, s = p - 1; v < e && *v < *s;
                 s = v, v++)
                __swap(s, v);
        return;
    }

    if (bn < __INSERT_THRESH) {
        for (int *p = b, *v; p < e;
             p++) // Insert Sort B into A
            for (s = p, v = p - 1; s > a && *s < *v;
                 s = v, v--)
                __swap(s, v);
        return;
    }

    // Find the pivot points.  Basically this is just
    // finding the point in 'a' where we can swap in the
    // first part of 'b' such that after the swap the last
    // element in 'a' will be less than or equal to the
    // least element in 'b'
    int *pa = a, *pb = b;

    for (s = a; s < b && pb < e; s++)
        if (*pb < *pa)
            pb++;
        else
            pa++;
    pa += b - s;

    // Swap first part of b with last part of a
    for (int *la = pa, *fb = b; la < b; la++, fb++)
        __swap(la, fb);

    // Now merge the two sub-array pairings
    merge(a, pa - a, pb - b);
    merge(b, pb - b, e - pb);
} // merge_array_inplace

#undef __swap
#undef __INSERT_THRESH

// Merge Sort Implementation
void merge_sort(int* a, size_t n)
{
    size_t m = (n + 1) / 2;

    // Sort first and second halves
    if (m > 1)
        merge_sort(a, m);

    if (n - m > 1)
        merge_sort(a + m, n - m);

    // Now merge the two sorted sub-arrays together
    merge(a, m, n - m);
}

// Function to print an array
void print_array(int a[], size_t n)
{
    if (n > 0) {
        cout <<" "<< a[0];
        for (size_t i = 1; i < n; i++)
            cout <<" "<< a[i];
    }
    cout <<"\n";
}

int main() {
    int n;
    cin >> n;
    a = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, n);
    print_array(a, n);
    free(a);
    return 0;
}
