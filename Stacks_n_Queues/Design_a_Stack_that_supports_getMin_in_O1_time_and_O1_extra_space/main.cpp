// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

stack<int> minStack;

void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
	if(minStack.empty() || a <= minStack.top()) minStack.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return (s.size() == n);
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	int temp = s.top();
	s.pop();
	if(temp == minStack.top()) minStack.pop();
	return temp;
}

int getMin(stack<int>& s){
	// Your code goes here
	return minStack.top();
}