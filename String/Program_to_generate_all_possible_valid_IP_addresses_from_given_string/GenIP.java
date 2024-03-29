//{ Driver Code Starts
import java.util.*;
class GenIP {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            Solution sln = new Solution();
            ArrayList<String> str = sln.genIp(s);
            Collections.sort(str);
            if(str.size() == 0)
                System.out.println(-1);
            else{
                for (String u : str) {
                    System.out.println(u);
                }
            }
        }
    }
}
// } Driver Code Ends


/*complete the Function*/

class Solution {
    public ArrayList<String> genIp(String str) {
        // code here
        ArrayList<String> ans = new ArrayList<>();
        int n=str.length();
        if(n<4 || n>12){
            ans.add("-1"); return ans;
        }
        
        HashSet<String> set = new HashSet<>();
        for(int i=0; i<256; i++){
            set.add(String.valueOf(i));
        }
        
        for(int i=1; i<=3; i++){
            StringBuilder ip1 = new StringBuilder(str);
            ip1.insert(i,".");
            if(!set.contains(ip1.substring(0,i))) continue;
            for(int j=i+2; j<=i+4 && j<ip1.length(); j++){
                StringBuilder ip2 = new StringBuilder(ip1);
                ip2.insert(j,".");
                if(!set.contains(ip2.substring(i+1,j))) continue;
                for(int k=j+2; k<=j+4 && k<ip2.length(); k++){
                    StringBuilder ip3 = new StringBuilder(ip2);
                    ip3.insert(k,".");
                    if(set.contains(ip3.substring(j+1,k)) && set.contains(ip3.substring(k+1))){
                        ans.add(ip3.toString());
                    };
                }
            }
        }
        return ans;
    }
}