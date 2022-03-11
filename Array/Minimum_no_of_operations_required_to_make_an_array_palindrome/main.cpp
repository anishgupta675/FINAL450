// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int reverseDigits(int num)
    {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }

    /* Function to check if n is Palindrome*/
    int isPalindrome(int n)
    {

        // get the reverse of n
        int rev_n = reverseDigits(n);

        // Check if rev_n and n are same or not.
        if (rev_n == n)
            return 1;
        else
            return 0;
    }
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i = 0; i < n; i++)
    	    if(!isPalindrome(a[i])) return 0;
    	return 1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends
