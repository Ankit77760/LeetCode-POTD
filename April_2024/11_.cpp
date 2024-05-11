//857. Minimum Cost to Hire K Workers
/*
There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

Every worker in the paid group must be paid at least their minimum wage expectation.
In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
 

Constraints:

n == quality.length == wage.length
1 <= k <= n <= 104
1 <= quality[i], wage[i] <= 104
*/

//Solution
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,int k) {
        int n = quality.size();
        double minCost = DBL_MAX; // Equivalent to float('inf') in Python
        double qualityTillNow = 0;

        // Vector to store ratio and quality, which will be used to create a
        // min-heap
        vector<pair<double, int>> wageQualityRatio;
        for (int i = 0; i < n; ++i) {
            wageQualityRatio.emplace_back(
                static_cast<double>(wage[i]) / quality[i], quality[i]);
        }

        // Sort by ratio to mimic a min-heap pop operation
        sort(wageQualityRatio.begin(), wageQualityRatio.end());

        // Max-heap to store qualities; C++ priority_queue is a max-heap by
        // default
        priority_queue<int> highQualityWorkers;

        for (int i = 0; i < n; ++i) {
            double ratio = wageQualityRatio[i].first;
            int qua = wageQualityRatio[i].second;

            qualityTillNow += qua;
            highQualityWorkers.push(qua);

            // If we have more than k workers, remove the one with the highest
            // quality
            if (highQualityWorkers.size() > k) {
                qualityTillNow -= highQualityWorkers.top();
                highQualityWorkers.pop();
            }

            // Calculate cost when we have exactly k workers
            if (highQualityWorkers.size() == k) {
                minCost = min(minCost, qualityTillNow * ratio);
            }
        }

        return minCost;
    }
};