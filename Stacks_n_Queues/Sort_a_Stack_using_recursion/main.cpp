// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void insert_sorted(stack<int> &s,int num)
{
    if(s.empty())
    {
        s.push(num);
        return;
    }
    else if(num<s.top())
    {
        int ans=s.top();
        s.pop();//you forget to include this and because of this it was giving segmentation fault
        insert_sorted(s,num);
        s.push(ans);
    }
    else
    {
        s.push(num);
    }
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
   return;
   
   int num=s.top();
   s.pop();
   sort();
   insert_sorted(s,num);
}