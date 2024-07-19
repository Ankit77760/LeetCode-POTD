//1380. Lucky Numbers in a Matrix
/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
Accepted
188,646
Submissions
242,245
*/

//Solutions
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int>ans;
        
        vector<int>row_min(n,INT_MAX);
        vector<int>col_max(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int el=matrix[i][j];
                row_min[i]=min(row_min[i],el);
                col_max[j]=max(col_max[j],el);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int el=matrix[i][j];
                if(el==row_min[i] && el==col_max[j]){
                    ans.push_back(el);
                }
            }
        }
        return ans;
        
    }
};