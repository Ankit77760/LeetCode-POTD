//826. Most Profit Assigning Work
/*
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.

 

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
Example 2:

Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0
 

Constraints:

n == difficulty.length
n == profit.length
m == worker.length
1 <= n, m <= 104
1 <= difficulty[i], profit[i], worker[i] <= 105
*/

//Solutions
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        
        // Pair difficulty with profit
        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());

        // Sort worker abilities
        sort(worker.begin(), worker.end());

        // Track max profit for each difficulty
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, jobs[i].second);
            jobs[i].second = maxProfit;
        }

        int ans = 0;
        int j = 0;
        for (int i = 0; i < worker.size(); ++i) {
            // Find the most difficult job that the worker can do
            while (j < n && jobs[j].first <= worker[i]) {
                ++j;
            }
            if (j > 0) {
                ans += jobs[j - 1].second;
            }
        }

        return ans;
    }
};
