#include<bits/stdc++.h>
using namespace std;

int *input = nullptr, *output = nullptr;

// function to check if input array is
// permutable to output array
bool checkStackPermutation(int ip[], int op[], int n)
{
     // we will be pushing elements from input array to stack uptill top of our stack
     //  matches with first element of output array
      stack<int>s;
      
    // will maintain a variable j to iterate on output array
      int j=0;
   
    // will iterate one by one in input array
      for(int i=0;i<n;i++)
      {
        // pushed an element from input array to stack
        s.push(ip[i]);
        // if our stack isn't empty and top matches with output array
        // then we will keep popping out from stack uptill top matches with
        // output array
        while(!s.empty() and s.top()==op[j])
        {
          s.pop();
          // increasing j so next time we can compare next element in output array
          j++;
        }
      }
       
      // if output array was a correct permutation of input array then
      // by now our stack should be empty
      if(s.empty())
      {
        return true;
      }
      return false; 
       
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> input[i];
    for(int i = 0; i < n; i++)
        cin >> output[i];
    cout << ((checkStackPermutation(input, output, n)) ? "true" : "false") << endl;
    return 0;
}