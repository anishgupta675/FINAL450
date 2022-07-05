#include<bits/stdc++.h>

using namespace std;

class Solution {
    bool find(vector<string> wordList, string word) {
        for(auto i: wordList)
            if(!word.compare(i)) return true;
        return false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(!find(wordList, endWord)) return 0;
        unordered_map<string, bool> Vmap;
        for(int i = 0; i < wordList.size(); i++)
            Vmap[wordList[i]] = false;
        queue<string> q;
        int length = 1;
        q.push(beginWord);
        Vmap[beginWord] = true;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                string w = q.front();
                q.pop();
                if(!w.compare(endWord)) return length;
                wordMatch(w, Vmap, q);
            }
            length++;
        }
        return 0;
    }
    void wordMatch(string w, unordered_map<string, bool> Vmap, queue<string> q) {
        for(int i = 0; i < w.length(); i++) {
            for(int j = 0; j < 26; j++) {
                w[i] = (char)('a' + j);
                if(Vmap.find(w) != Vmap.end() && !Vmap[w]) {
                    q.push(w);
                    Vmap[w] = true;
                }
            }
        }
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