#include<bits/stdc++.h>

using namespace std;

int *price = nullptr;

int getMaxProfit(int *price, int n) {
    int profit = 0;
    for(int i = 1; i < n; i++) {
        int sub = price[i] - price[i - 1];
        if(sub > 0) profit+= sub;
    }
    return profit;
}

int main() {
    int n;
    cin >> n;
    price = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        cin >> price[i];
    cout << getMaxProfit(price, n) << endl;
    free(price);
    return 0;
}
