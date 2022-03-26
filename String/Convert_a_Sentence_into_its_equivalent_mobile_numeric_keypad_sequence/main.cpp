// { Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends

const char *keypad[26] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};

string printSequence(string S)
{
    //code here.
    string res = "";
    for(int i = 0; i < S.length(); i++) {
        if(S[i] == ' ') res+= "0";
        else res+= keypad[toupper(S[i]) - 'A'];
    }
    return res;
}
