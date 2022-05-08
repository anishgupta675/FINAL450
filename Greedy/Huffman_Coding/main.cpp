// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class HuffmanNode {
public:
    int weight;
    char charContent;
    
    HuffmanNode* leftChild;
    HuffmanNode* rightChild;
    
public:
    HuffmanNode (char charContent, int weight) {
        this->charContent = charContent;
        this->weight = weight;
        leftChild = rightChild = NULL;
    }
};

class CompareHuffmanNode {
public:
    bool operator()(HuffmanNode* const& p1, HuffmanNode* const& p2)
    {
        return p1->weight > p2->weight;
    }
};

class Solution
{
private:
    void fetchAllEncodes(const HuffmanNode *root, string &path, vector<string> &resultCollection) {
        if (root->leftChild == NULL && root->rightChild == NULL) {
            resultCollection.push_back(path);
            return;
        }
        
        path += '0';
        fetchAllEncodes((root->leftChild), path, resultCollection);
        path.pop_back();
        path += '1';
        fetchAllEncodes((root->rightChild), path, resultCollection);
        path.pop_back();
    }
public:
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
	    // Code here
	    if (N == 0) {
	        return {};
	    }
	    
	    if (N == 1) {
	        return {"0"};
	    }
	    
	    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareHuffmanNode> q;
	    
	    for (int i = 0; i < N; i++) {
	        q.push(new HuffmanNode(S[i], f[i]));
	    }
	
	    while (q.size() > 1) {
	        HuffmanNode* node1 = q.top();
	        q.pop();
	        HuffmanNode* node2 = q.top();
	        q.pop();
	        
	        HuffmanNode* combinedNode = new HuffmanNode('\0', node1->weight + node2->weight);
	        combinedNode->leftChild = node1;
	        combinedNode->rightChild = node2;

	        q.push(combinedNode);
	    }
	    
	    HuffmanNode* root = q.top();
	    vector<string> resultCollection;
	    string path;
	    
	    fetchAllEncodes(root, path, resultCollection);
	    return resultCollection;
	}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends