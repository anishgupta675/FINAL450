#include <iostream>

using namespace std;

int *arr = nullptr;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void rearrange(int *arr, int n) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            if(i != j) swap(&arr[i], &arr[j]);
            j++;
        }
    }
}

void display(int *arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
	// cout<<"GfG!";
	int n;
	cin >> n;
	arr = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
	    cin >> arr[i];
    rearrange(arr, n);
	display(arr, n);
	free(arr);
	return 0;
}
