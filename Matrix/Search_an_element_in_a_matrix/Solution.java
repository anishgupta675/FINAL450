import java.util.*;
class Solution {
    public boolean binarySearch(int[] row, int low, int high, int target) {
        if(low > high) return false;
        if(row[low] == target || row[high] == target) return true;
        int mid = (low + high) / 2;
        if(row[mid] == target) return true;
        if(row[mid] > target) return binarySearch(row, low + 1, mid - 1, target);
        return binarySearch(row, mid + 1, high - 1, target);
    }
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix[0][0] > target || matrix[matrix.length - 1][matrix[matrix.length - 1].length - 1] < target) return false;
        for(int i = 0; i < matrix.length; i++)
            if(matrix[i][0] <= target && matrix[i][matrix[i].length - 1] >= target) return binarySearch(matrix[i], 0, matrix[i].length - 1, target);
        return false;
    }
    public static void main(String[] args) throws Exception {}
}