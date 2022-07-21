#include <iostream>
#include <vector>
using namespace std;
 
const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;
 
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// Returns true if key presents in trie, else
// false
bool search(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;
 
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
 
// returns true if string can be segmented into
// space separated words, otherwise returns false
bool wordBreak(string str, TrieNode* root)
{
    int size = str.size();
 
    // Base case
    if (size == 0)
        return true;
 
    // Try all prefixes of lengths from 1 to size
    for (int i = 1; i <= size; i++) {
        // The parameter for search is str.substr(0, i)
        // str.substr(0, i) which is prefix (of input
        // string) of length 'i'. We first check whether
        // current prefix is in dictionary. Then we
        // recursively check for remaining string
        // str.substr(i, size-i) which is suffix of
        // length size-i
        if (search(root, str.substr(0, i))
            && wordBreak(str.substr(i, size - i), root))
            return true;
    }
 
    // If we have tried all prefixes and none
    // of them worked
    return false;
}

string data;
vector<string> dictionary;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        getline(cin, data);
        dictionary.push_back(data);
    }
    struct TrieNode *root = getNode();
    for(int i = 0; i < n; i++)
        insert(root, dictionary[i]);
    getline(cin, data);
    cout << wordBreak(data, root) << endl;
    return 0;
}