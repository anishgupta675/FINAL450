//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        if(!dividend || !divisor) return 0;
        int sign = (dividend < 0) ^ (divisor < 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        if(divisor == 1) return (!sign) ? dividend : -dividend;
        long long ans = exp(log(dividend) - log(divisor)) + 0.0000000001;
        return (!sign) ? ans : -ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends