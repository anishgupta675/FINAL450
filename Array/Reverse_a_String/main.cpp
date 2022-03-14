#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void swap(char *xp, char *yp) {
        char temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i <= j; i++, j--)
            swap(&s[i], &s[j]);
    }
};

vector<char> s;
Solution sol;

void display(vector<char> s) {
    for(int i = 0; i < s.size(); i++)
        cout << s[i] << "";
    cout << "\n";
}

int main() {
    char data;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        s.push_back(data);
    }
    sol.reverseString(s);
    display(s);
    return 0;
}
