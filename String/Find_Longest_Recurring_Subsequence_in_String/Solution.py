#User function Template for python3

class Solution:
	def LongestRepeatingSubsequence(self, str):
		# Code here
		dp = [[-1 for j in range(len(str))] for i in range(len(str))]
		def dfs(dp, i, j):
		    if i == len(str) or j == len(str):
		        return 0
		    if dp[i][j] != -1:
		        return dp[i][j]
		    if str[i] == str[j] and i != j:
		        dp[i][j] = 1 + dfs(dp, i + 1, j + 1)
		        return dp[i][j]
		    dp[i][j] = max(dfs(dp, i + 1, j), dfs(dp, i, j + 1))
		    return dp[i][j]
		return dfs(dp, 0, 0)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		str = input()
		ob = Solution()
		ans = ob.LongestRepeatingSubsequence(str)
		print(ans)

# } Driver Code Ends