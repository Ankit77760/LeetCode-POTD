//1937. Maximum Number of Points with Cost
/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.
 

Example 1:


Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
Example 2:


Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
 

Constraints:

m == points.length
n == points[r].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= points[r][c] <= 105
Accepted
102,706
Submissions
260,503
*/

//Solutions
class Solution {
public:
    static long long maxPoints(vector<vector<int>>& points) {
        const int r=points.size(), c=points[0].size();
        vector<vector<long long>> dp(2, vector<long long>(c, 0));

        // Initialize 0th row
        for (int j=0; j<c; j++)
            dp[0][j]=points[0][j];

        // DP Calculation
        for (int i=1; i < r; i++) {
            vector<long long> left(c, 0), right(c, 0);

             // Compute max from right downto col j=c-1...0
            right[c-1]=dp[(i-1)&1][c-1];
            for (int j=c-2; j >= 0; j--)
                right[j] = max(right[j+1]-1, dp[(i-1)&1][j]);

            // Compute max from left to col j=0...c-1
            left[0]=dp[(i-1)&1][0];
            dp[i&1][0]=max(left[0], right[0])+points[i][0];
            for (int j=1; j < c; j++){
                left[j]=max(left[j-1]-1, dp[(i-1)&1][j]);
                dp[i&1][j] = max(left[j], right[j])+points[i][j];// update DP
            }
        }

        // Find the maximum value
        return *max_element(dp[(r-1)&1].begin(), dp[(r-1)&1].end());
    }
};



auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
