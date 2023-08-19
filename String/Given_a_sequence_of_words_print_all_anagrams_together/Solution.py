#User function Template for python3

class Solution:
    def Anagrams(self, words, n):
        '''
        words: list of word
        n:      no of words
        return : list of group of anagram {list will be sorted in driver code (not word in grp)}
        '''
        
        #code here
        set_string = {}
        for i in range(n):
            set_string.add(sorted(sorted(words[i]), key=str.upper))
        list_string = list(set_string)
        list_string.sort()
        res = []
        for i in range(len(list_string)):
            data = []
            for j in range(n):
                if list_string[i].lower() == words[j].lower():
                    data.append(words[j])
            res.append(data)
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ =='__main__':
    t= int(input())
    for tcs in range(t):
        n= int(input())
        words=input().split()
        
        ob = Solution()
        ans = ob.Anagrams(words,n)
        
        for grp in sorted(ans):
            for word in grp:
                print(word,end=' ')
            print()

# } Driver Code Ends