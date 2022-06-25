// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
public:
    typedef pair<int, pair<int, int>> ppi;
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> res;
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
       
        for (int i=0; i<K; i++) {
            pq.push({arr[i][0], {i, 0}});
        }
       
        while (!pq.empty()) {
            ppi minNode = pq.top();
            pq.pop();
           
            res.push_back(minNode.first);
           
            int arrIdx = minNode.second.first;
            int arrSubIdx = minNode.second.second+1;
           
            if (arrSubIdx < arr[arrIdx].size()) {
                pq.push({arr[arrIdx][arrSubIdx], {arrIdx, arrSubIdx}});   
            }
        }
       
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends