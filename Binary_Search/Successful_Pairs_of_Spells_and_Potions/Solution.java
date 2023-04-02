class Solution {
    private int ans = 0;
    private boolean checkPairs(int spell, int potion, long success) { return (spell * potion >= success) ? true : false; }
    private void getPairs(int[] potions, int low, int high, int spell, long success) {
        if(low > high) return;
        int mid = (low + high) >> 1;
        if(checkPairs(spell, potions[mid], success)) {
            ans = mid;
            getPairs(potions, low, mid - 1, spell, success);
        } else getPairs(potions, mid + 1, high, spell, success);
    }
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int[] res = new int[spells.length];
        for(int i = 0; i < res.length; i++) {
            getPairs(potions, 0, potions.length, spells[i], success);
            res[i] = ans;
            ans = 0;
        }
        return res;
    }
}