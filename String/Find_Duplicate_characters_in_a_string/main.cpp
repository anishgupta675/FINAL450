#include <bits/stdc++.h>
using namespace std;
string str;
void printDups(string str)
{
    map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }

    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}
int main() {
    getline(cin, str);
    printDups(str);
    return 0;
}
