#include<bits/stdc++.h>

using namespace std;

class Test {
public:
    bool checkLength(string first, string second, string result) {
        if(first.length() + second.length() != result.length()) return false;
        else return true;
    }
    string sortString(string str) {
        sort(str.begin(), str.end());
        return str;
    }
    bool shuffleCheck(string first, string second, string result) {
        first = sortString(first);
        second = sortString(second);
        result = sortString(result);
        int i = 0, j = 0, k = 0;
        while(k != result.length()) {
            if(i < first.length() && first[i] == result[k]) i++;
            else if(j < second.length() && second[i] == result[k]) j++;
            else return false;
            k++;
        }
        if(i < first.length() || j < second.length()) return false;
        return true;
    }
};

string first, second, result;
vector<string> results;
Test test;

int main() {
    getline(cin, first);
    getline(cin, second);
    while(getline(cin, result)) {
        if(result.length() == 0) break;
        results.push_back(result);
    }
    for(vector<string>::iterator ptr = results.begin(); ptr < results.end(); ptr++) {
        if(test.checkLength(first, second, *ptr) == true && test.shuffleCheck(first, second, *ptr) == true) cout << *ptr << " is a valid shuffle of " << first << " and " << second << endl;
        else cout << *ptr << " is not a valid shuffle of " << first << " and " << second << endl;
    }
    return 0;
}
