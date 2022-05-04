#include <iostream>
#include <vector>
#include <set>
 
using namespace std;

vector<int> arr;

void solve(vector<int>& arr) {
    set<int> s;
    vector<int> ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--) { //traversing the array backwards
        s.insert(arr[i]); // inserting the element into set
        auto it = s.upper_bound(arr[i]); // finding upper bound
        if(it == s.end()) arr[i] = -1; // if upper_bound does not exist then -1
        else arr[i] = *it; // if upper_bound exists, lets take it
    }
}
 
void printArray(vector<int>& arr) {
    for(int i : arr) cout << i << " ";
    cout << "\n";
}

int main() {
    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        arr.push_back(data);
    }
    solve(arr);
    printArray(arr);
    return 0;
}