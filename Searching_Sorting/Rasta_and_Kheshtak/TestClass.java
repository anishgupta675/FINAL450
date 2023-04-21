import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class TestClass {

    private static Scanner sc = new Scanner(System.in);

    private static int maximizeSubsquare(int[][] a, int[][] b, int n, int m, int x, int y) {
        int min_size = Math.min(n, Math.min(m, Math.min(x, y))), low = 1, high = min_size, ans = 0;
        int[] pwr_arr = new int[(min_size * min_size) + 1];
        int[] roll_hash = new int[Math.max(m, y)];
        HashSet<Integer> found_k1 = new HashSet<Integer>();
        pwr_arr[0] = 1;
        for(int i = 0; i < pwr_arr.length; i++) pwr_arr[i] = (pwr_arr[i - 1] * 1000) % Integer.MAX_VALUE;
        while(low <= high) {
            int mid = low + ((high - low) >> 1), p_ptr = 0, i = mid - 1;
            roll_hash[0] = 0;
            while(i >= 0) {
                int j = mid - 1;
                while(j >= 0) {
                    roll_hash[0]+= a[i][j];
                    p_ptr++;
                    j--;
                }
                i--;
            }
            found_k1.add(roll_hash[0]);
            int k = 1, k1_col_start = 1, k1_col_end = mid;
            while(k1_col_end < m) {
                int row = mid - 1, l_side_sum = 0, r_side_sum = 0, l_pwr_ptr = mid - 1, r_pwr_ptr = 0;
                while(row >= 0) {
                    l_side_sum+= a[row][k1_col_start - 1] * pwr_arr[l_pwr_ptr];
                    r_side_sum+= a[row][k1_col_end] * pwr_arr[r_pwr_ptr];
                    l_pwr_ptr+= mid;
                    r_pwr_ptr+= mid;
                    row--;
                }
                roll_hash[k] = ((roll_hash[k - 1] - l_side_sum) * 1000) + r_side_sum;
                found_k1.add(roll_hash[k]);
                k++;
                k1_col_start++;
                k1_col_end++;
            }
            int k1_row_start = 1, k1_row_end = mid;
            while(k1_row_end < n) {
                int up_row_sum = 0, down_row_sum = 0, roll_hash_ptr = 0;
                k1_col_start = 0;
                k1_col_end = mid - 1;
                while(k1_col_end < m) {
                    if(k1_col_start == 0) {
                        k = 1;
                        for(i = k1_col_start; i < k1_col_end + 1; i++) {
                            up_row_sum+= a[k1_row_start - 1][i] * pwr_arr[(mid - k) + (mid - 1) * mid];
                            down_row_sum+= a[k1_row_end][i] * pwr_arr[(mid - k)];
                            k++;
                        }
                    } else {
                        up_row_sum = ((up_row_sum - (a[k1_row_start - 1][k1_col_start - 1] * pwr_arr[(mid - 1) + ((mid - 1) * mid)])) * 1000) + (a[k1_row_start - 1][k1_col_end] * pwr_arr[(mid - 1) * mid]);
                        down_row_sum = ((down_row_sum - (a[k1_row_end][k1_col_start - 1] * pwr_arr[mid - 1])) * 1000) + (a[k1_row_end][k1_col_end] * pwr_arr[0]);
                    }
                    roll_hash[roll_hash_ptr] = ((roll_hash[roll_hash_ptr] - up_row_sum) * pwr_arr[mid]) + down_row_sum;
                    found_k1.add(roll_hash[roll_hash_ptr]);
                    roll_hash_ptr++;
                    k1_col_start++;
                    k1_col_end++;
                }
                k1_row_start++;
                k1_row_end++;
            }
            boolean cm_sq_fnd = false;
            p_ptr = 0;
            i = mid - 1;
            roll_hash[0] = 0;
            while(i >= 0) {
                int j = mid - 1;
                while(j >= 0) {
                    roll_hash[0]+= b[i][j] * pwr_arr[p_ptr];
                    p_ptr++;
                    j--;
                }
                i--;
            }
            if(found_k1.contains(roll_hash[0])) cm_sq_fnd = true;
            if(!cm_sq_fnd) {
                int k2_col_start = 1, k2_col_end = mid;
                k = 1;
                while(k2_col_end < y) {
                    int row = mid - 1, l_side_sum = 0, r_side_sum = 0, l_pwr_ptr = mid - 1, r_pwr_ptr = 0;
                    while(row >= 0) {
                        l_side_sum+= b[row][k2_col_start - 1] * pwr_arr[l_pwr_ptr];
                        l_pwr_ptr+= mid;
                        r_pwr_ptr+= mid;
                        row--;
                    }
                    roll_hash[k] = ((roll_hash[k - 1] - l_side_sum) * 1000) + r_side_sum;
                    if(found_k1.contains(roll_hash[k])) {
                        cm_sq_fnd = true;
                        break;
                    }
                    k++;
                    k2_col_start++;
                    k2_col_end++;
                }
            }
            if(!cm_sq_fnd) {
                int k2_row_start = 1, k2_row_end = mid;
                while(k2_row_end < x) {
                    int k2_col_start = 0, k2_col_end = mid - 1, up_row_sum = 0, down_row_sum = 0, roll_hash_ptr = 0;
                    while(k2_col_end < y) {
                        if(k2_col_start == 0) {
                            k = 1;
                            for(i = k2_col_start; i < k2_col_end + 1; i++) {
                                up_row_sum+= b[k2_row_start - 1][i] * pwr_arr[(mid - k) + ((mid - 1) * mid)];
                                down_row_sum+= b[k2_row_end][i] * pwr_arr[(mid - k)];
                                k++;
                            }
                        } else {
                            up_row_sum = ((up_row_sum - (b[k2_row_start - 1][k2_col_start - 1] * pwr_arr[(mid - 1) + ((mid - 1) * mid)])) * 1000) + b[k2_row_start - 1][k2_col_end] * pwr_arr[(mid - 1) * mid];
                            down_row_sum = ((down_row_sum - (b[k2_row_end][k2_col_start - 1] * pwr_arr[mid - 1])) * 1000) + (b[k2_row_end][k2_col_end] * pwr_arr[0]);
                        }
                        roll_hash[roll_hash_ptr] = ((roll_hash[roll_hash_ptr] - up_row_sum) * pwr_arr[mid]) + down_row_sum;
                        if(found_k1.contains(roll_hash[roll_hash_ptr])) {
                            cm_sq_fnd = true;
                            break;
                        }
                        // TODO
                    }
                }
            }
        }
        return ans;
    }

    private static void solve() {
        int n = sc.nextInt(), m = sc.nextInt();
        int[][] a = new int[n][m];
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) a[i][j] = sc.nextInt();
        int x = sc.nextInt(), y = sc.nextInt();
        int[][] b = new int[x][y];
        for(int i = 0; i < x; i++) for(int j = 0; j < y; j++) b[i][j] = sc.nextInt();
    }

    public static void main(String args[] ) throws Exception {
        //BufferedReader
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // String name = br.readLine();                // Reading input from STDIN
        // System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        int tc = 1;
        // tc = sc.nextInt();
        for(int i = 0; i < tc; i++) {
            // System.out.print("Case #" + t + ": ");
            solve();
        }
    }
}