#include <iostream>
#include <algorithm>
using namespace std;

// A job has start time, finish time and profit.
struct Job
{
    int start, finish, profit;
};

// A utility function that is used for sorting events
// according to finish time
bool myfunction(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job.  "index" is index of the current job.  This function
// returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish
// time.
int binarySearch(Job jobs[], int index)
{
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;

    // Perform binary Search iteratively
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }

    return -1;
}

// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr+n, myfunction);

    // Create an array to store solutions of subproblems.  table[i]
    // stores the profit for jobs till arr[i] (including arr[i])
    int *table = new int[n];
    table[0] = arr[0].profit;

    // Fill entries in table[] using recursive property
    for (int i=1; i<n; i++)
    {
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = binarySearch(arr, i);
        if (l != -1)
            inclProf += table[l];

        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i-1]);
    }

    // Store result and free dynamic memory allocated for table[]
    int result = table[n-1];
    delete[] table;

    return result;
}

Job *arr;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
    cout << findMaxProfit(arr, n) << endl;
    free(arr);
    return 0;
}
