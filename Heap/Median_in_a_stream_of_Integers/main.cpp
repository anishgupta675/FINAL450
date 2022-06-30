// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> left;

    priority_queue<int, vector<int>, greater<int> > right;

    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(right.size()==0) right.push(x);

        else if(left.size()==0) left.push(x);

        else{

            if(left.top()<x) right.push(x);

            else left.push(x);

        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        while(left.size()+1 < right.size()){

            left.push(right.top());

            right.pop();

        }

        while(left.size() > right.size()){

            right.push(left.top());

            left.pop();

        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        balanceHeaps();

        double ans=0;

        if(left.size()+right.size()==0) return ans;

        if( (left.size()+right.size()) % 2 == 0)

            ans = ((left.top()*1.0)+(right.top()*1.0))/2;

        else

            ans = right.top();

        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends