#include <bits/stdc++.h>

using namespace std;




typedef long long ll;

typedef unsigned long long ull;

typedef long double lld;




void merge(vector<ll> &arr, ll p, ll q, ll r) {



// Create L ← A[p..q] and M ← A[q+1..r]

ll n1 = q - p + 1;

ll n2 = r - q;




ll L[n1], M[n2];




for (ll i = 0; i < n1; i++)

L[i] = arr[p + i];

for (ll j = 0; j < n2; j++)

M[j] = arr[q + 1 + j];




// Maintain current index of sub-arrays and main array

ll i, j, k;

i = 0;

j = 0;

k = p;




// Until we reach either end of either L or M, pick larger among

// elements L and M and place them in the correct position at A[p..r]

while (i < n1 && j < n2) {

if (L[i] <= M[j]) {

arr[k] = L[i];

i++;

} else {

arr[k] = M[j];

j++;

}

k++;

}




// When we run out of elements in either L or M,

// pick up the remaining elements and put in A[p..r]

while (i < n1) {

arr[k] = L[i];

i++;

k++;

}




while (j < n2) {

arr[k] = M[j];

j++;

k++;

}

}




// Divide the array into two subarrays, sort them and merge them

void mergeSort(vector<ll> &arr, ll l, ll r) {

if (l < r) {

// m is the point where the array is divided into two subarrays

ll m = l + (r - l) / 2;




mergeSort(arr, l, m);

mergeSort(arr, m + 1, r);




// Merge the sorted subarrays

merge(arr, l, m, r);

}

}




ll UpperBound(vector<ll> &arr, ll x) {

ll l=0, m, r=arr.size()-1, ans;

while (l<r) {

m= l+ (r-l)/2;



if (arr[m] <= x) {

l=m+1;

}

else {

r=m;

}



}

//This line is to when the query is larger than the greatest number in the array.

// for ex: if Q=10 in an array of {1, 2, 3, 4}.

// in this case the answer should be "4 10" as it can beat all the stories.

// Had i simply returned the value "l" without the if case below, the output would have been "3 6"



if (l== arr.size()-1 && arr[l] <= x) l++;

return l;

}


int main() {

ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

ll n;

cin >> n;

vector<ll> arr(n);

for(ll i=0; i<n; i++) {

cin >> arr[i];

}

mergeSort(arr, 0, arr.size()-1);

vector<ll> prefix(n+1);

prefix[0]=0;

for(ll i=1; i<=n; i++) {

prefix[i] = prefix[i-1] + arr[i-1];

}

ll q, Q;

cin >> q;

mergeSort(arr, 0, arr.size()-1);

for(ll i=0; i<q; i++) {

cin >> Q;



ll ind=UpperBound(arr, Q);



cout << ind <<" "<< prefix[ind] << "\n";



}

return 0;

}
