#include <iostream>
#include <string>

using namespace std;

string str;

void printAllSubSequences(string str, int n, string curr, int index) {
    if(index == n) return;
    if(!curr.empty()) cout << curr << endl;
    for(int i = index + 1; i < n; i++) {
        curr+= str[i];
        printAllSubSequences(str, n, curr, i);
        curr = curr.erase(curr.length() - 1);
    }
    return;
}

int main() {
	// cout<<"GfG!";
	getline(cin, str);
	printAllSubSequences(str, str.length(),"" , -1);
	return 0;
}
