import java.util.*;
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length <= 1) return intervals;
        Arrays.sort(intervals, (arr1, arr2) -> Integer.compare(arr1[0], arr2[0]));
        int[] current_interval = intervals[0];
        List<int[]> res = new ArrayList<int[]>();
        for(int i = 0; i < intervals.length; i++) {
            if(current_interval[1] >= intervals[i][0]) current_interval[1] = Math.max(current_interval[1], intervals[i][1]);
            else {
                res.add(current_interval);
                current_interval = intervals[i];
            }
        }
        res.add(current_interval);
        return res.toArray(new int[(res.size())][]);
    }
    public static void main(String[] args) throws Exception {}
}