class Solution {
    int ans = 0;
    bool checkPairs(int spell, int potion, int success) { return (spell * potion >= success); }
    void getPairs(vector<int> &potions, int low, int high, int spell, int success) {
        if(low == high) return;
        int mid = (low + mid) >> 1;
        if(checkPairs(spell, potions[mid], success)) {
            ans = mid;
            getPairs(potions, low, mid - 1, spell, success);
        } else getPairs(potions, mid + 1, high, spell, success);
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size(), 0);
        sort(potions.begin(), potions.end());
        for(int i : spells) {
            getPairs(potions, 0, potions.size(), i, success);
            res.push_back(ans);
            ans = 0;
        }
        return res;
    }
};