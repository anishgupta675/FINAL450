//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends

int binaryToDecimal(string n) {
    int dec_value = 0, base = 1, len = n.length();
    string num = n;
    for(int i = len - 1; i >= 0; i--) {
        if(num[i] == '1') dec_value+= base;
        base*= 2;
    }
    return dec_value;
}

int getNum(char num) {
    return ((num == '0') ? 0 : 1);
}

/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
string datum;
vector<int> data;
vector<vector<int>> res;
unordered_set<int> umap;
for(int i = 0; i < row; i++) {
    datum = "";
    data.clear();
    for(int j = 0; j < col; j++) {
        datum+= (M[i][j]) ? '1' : '0';
        data.push_back(M[i][j]);
    }
    int dec_value = binaryToDecimal(datum);
    if(umap.find(dec_value) == umap.end()) continue;
    else {
        res.push_back(data);
        umap.insert(dec_value);
    }
}
return res;
}