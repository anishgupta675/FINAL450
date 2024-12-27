#include <iostream>
#include <unordered_map>

using namespace std;

int *arr = nullptr;

void getArr(int *arr, int n, int k) {
    unordered_map<int, int> umap;
    for(int i = 0; i < n; i++)
        umap[arr[i]]++;
    for(auto i : umap)
        if(i.second > n / k) cout << i.first << " ";
    cout << "\n";
}

int main() {
	// cout<<"GfG!";
	int n, k;
	cin >> n;
	arr = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
	    cin >> arr[i];
	cin >> k;
	getArr(arr, n, k);
	free(arr);
	return 0;
}
