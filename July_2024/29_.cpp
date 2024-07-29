//1395. Count Number of Teams
/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.
Accepted
171,515
Submissions
250,649
*/

//Solutions
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;
        
        vector<pair<int, int>> soldiers;
        for (int i = 0; i < n; i++) {
            soldiers.push_back({rating[i], i});
        }
        sort(soldiers.begin(), soldiers.end());
        
        vector<int> indexMap(n);
        for (int i = 0; i < n; i++) {
            indexMap[soldiers[i].second] = i;
        }
        
        return countTeams(indexMap, n, true) + countTeams(indexMap, n, false);
    }
    
private:
    int countTeams(const vector<int>& indexMap, int n, bool ascending) {
        vector<int> bit(n + 1, 0);
        int teams = 0;
        
        for (int i = 0; i < n; i++) {
            int rank = indexMap[i] + 1;
            int left = ascending ? getSum(bit, rank - 1) : getSum(bit, n) - getSum(bit, rank);
            int right = ascending ? n - rank - (getSum(bit, n) - getSum(bit, rank)) : rank - 1 - getSum(bit, rank - 1);
            teams += left * right;
            update(bit, rank, 1);
        }
        
        return teams;
    }
    
    void update(vector<int>& bit, int index, int val) {
        while (index < bit.size()) {
            bit[index] += val;
            index += index & (-index);
        }
    }
    
    int getSum(const vector<int>& bit, int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }
        return sum;
    }
};