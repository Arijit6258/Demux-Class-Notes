// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
// 
/**
 * Problem statement :
 
 *  Given a m x n matrix mat and an integer threshold. Return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

Example 1:


Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
Example 2:

Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0
Example 3:

Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
Output: 3
Example 4:

Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
Output: 2
 

Constraints:

1 <= m, n <= 300
m == mat.length
n == mat[i].length
0 <= mat[i][j] <= 10000
0 <= threshold <= 10^5

**/


int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // replacing mat[i][j] with prefix sum
        int i, j, n, m;
        m = mat.size(), n = mat[0].size();
        
        // sum for first row
        for (j = 1; j < n; j++)
            mat[0][j] += mat[0][j - 1];
        
        // sum for first column
        for (i = 1; i < m; i++)
            mat[i][0] += mat[i - 1][0];
        
        // mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1]
        for (i = 1; i < m; i++) 
            for (j = 1; j < n; j++) 
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
                
        
        // prefix sum obtained
        // finding lenght using binary search for each i, j
        int maxlen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // TTT*FFF*
                // find last T
                int lo, hi, mid;
                lo = 0, hi = min(i , j) + 1;
                
                while(lo < hi) {
                    mid = lo + (hi - lo + 1)/2;
                    int a, b, c;
                    
                    // checking for bound of matrix
                    if (i - mid < 0)
                        b = 0;
                    else
                        b = mat[i - mid][j];
                    
                    if (j - mid < 0)
                        a = 0;
                    else
                        a = mat[i][j - mid];
                    
                    if (i - mid < 0 || j - mid < 0)
                        c = 0;
                    else
                        c = mat[i - mid][j - mid];
                    
                    int sum = mat[i][j] - a - b + c;
                    if (sum <= threshold)
                        lo = mid;
                    else
                        hi = mid - 1;
                }
                maxlen = max(lo, maxlen);
            }
        }
        return maxlen;
    }