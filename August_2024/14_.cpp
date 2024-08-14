//719. Find K-th Smallest Pair Distance
/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2
Accepted
154,665
Submissions
357,232
*/

//Solutions
#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestDistancePair(std::vector<int>& numbers, int k) {
        std::sort(numbers.begin(), numbers.end());
        int minDistance = 0, maxDistance = numbers.back() - numbers.front();
        
        while (minDistance < maxDistance) {
            int midDistance = minDistance + (maxDistance - minDistance) / 2;
            if (countPairsWithinDistance(numbers, midDistance) < k) {
                minDistance = midDistance + 1;
            } else {
                maxDistance = midDistance;
            }
        }
        
        return minDistance;
    }

private:
    int countPairsWithinDistance(const std::vector<int>& numbers, int targetDistance) {
        int count = 0, left = 0;
        for (int right = 1; right < numbers.size(); ++right) {
            while (numbers[right] - numbers[left] > targetDistance) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};