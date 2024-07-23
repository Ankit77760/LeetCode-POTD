//1636. Sort Array by Increasing Frequency
/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
Accepted
242,322
Submissions
306,710
*/

//Solutions
#include<bits/stdc++.h>
using namespace std;

static vector<int>ans(200,0);

class Solution {
public:
    static vector<int>ans;
    static bool comparator(int x,int y){
        if(ans[x+100]==ans[y+100]){
            return x>y;
        }
        return ans[x+100]<ans[y+100];
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        
        for(int num:nums){
            ans[num+100]++;
        }
        sort(nums.begin(),nums.end(),comparator);
        return nums;
    }
};
