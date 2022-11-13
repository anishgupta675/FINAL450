//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        
	    int t=Integer.parseInt(br.readLine().trim());
	    while(t > 0)
	    {
	        int n= Integer.parseInt(br.readLine().trim());
	        String x = br.readLine().trim();
	        String string_list[] = x.split(" ",n);
	        
	        Solution ob = new  Solution();
	        
	        List <List<String>> ans = ob.Anagrams(string_list);
	        
	        Collections.sort(ans, new Comparator<List<String>>(){
            public int compare(List<String> l1, List<String> l2) {
                    String s1 =  l1.get(0);
                    String s2 = l2.get(0);
                    
                    return s1.compareTo(s2);
                }
            });
	        
	        for(int i=0;i<ans.size();i++)
	        {
	            for(int j=0;j<ans.get(i).size();j++)
	            {
	                System.out.print(ans.get(i).get(j) + " ");
	            }
	            System.out.println();
	        }
	       
	       
            t--;
	    }
	}
    
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    public List<List<String>> Anagrams(String[] string_list) {
        // Code here
        HashSet<String> stringHashSet = new HashSet<>();

        for (String s: string_list){

            stringHashSet.add(sortString(s));

        }

        ArrayList<String> templist = new ArrayList<>(stringHashSet);

        Collections.sort(templist);

        List<List<String>> myList = new ArrayList<>();

        for (String st: templist){

            ArrayList<String> lists = new ArrayList<>();

            for (String s: string_list){

                if (st.equalsIgnoreCase(sortString(s))){

                    lists.add(s);

                }

            }

            myList.add(lists);

        }

        return myList;
    }
    String sortString(String str) {

        final int MAX_CHAR = 26;

        

        int letters[] = new int[MAX_CHAR];

 

        

        

        for (char x : str.toCharArray()) {

 

            

            

            

            letters[x - 'a']++;

        }

 

        

        

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < MAX_CHAR; i++) {

            for (int j = 0; j < letters[i]; j++) {

                stringBuilder.append((char) (i + 'a'));

            }

        }

        return stringBuilder.toString();

    }
}
