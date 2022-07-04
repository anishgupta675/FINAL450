#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> map;      
        if (find(wordList.begin(),wordList.end(),beginWord) == wordList.end()){
            wordList.push_back(beginWord);
        }
        
        int len = wordList[0].size();
        for (int i=0; i< wordList.size(); i++){
            for (int j=0; j< len; j++){
                string p = wordList[i];
                p.replace(j,1,"*");
                if (map.find(p) == map.end()){
                    vector v = {wordList[i]};
                    map.emplace(p,v);
                }
                else{
                    map[p].push_back(wordList[i]);
                }
            }
        }
        int transform = 1;    
        int level_pop = 0;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.emplace(beginWord);
        int level_node = 1; 
        int n = 0;
        bool edge = false;
        while (!q.empty()){
            if (q.front() == endWord){
                return transform;
            }
            for (int k=0; k< len; k++){
                string curr = q.front();
                curr.replace(k,1,"*");
                for (int i=0; i< map[curr].size(); i++){
                    if (visited.find(map[curr][i]) == visited.end()){
                        q.push(map[curr][i]);
                        n ++;
                        visited.emplace(map[curr][i]);
                        edge = true;
                    }     
                }  
            }
         
            level_pop ++;            
            if (level_pop == level_node){
                if (edge){
                    transform ++;
                }
                level_pop = 0;
                level_node = n;
                edge = false;
                n=0;
            }
            
            q.pop();  
            
        }
        return 0;
    }
};

string beginWord, endWord;
vector<string> wordList;
Solution sol;

int main() {
    int n;
    string data;
    getline(cin, beginWord);
    getline(cin, endWord);
    cin >> n;
    for(int i = 0; i < n; i++) {
        getline(cin, data);
        wordList.push_back(data);
    }
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}