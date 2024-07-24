//2191. Sort the Jumbled Numbers
/*
You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
 

Example 1:

Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
Explanation: 
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
Thus, the sorted array is [338,38,991].
Example 2:

Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
Output: [123,456,789]
Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
 

Constraints:

mapping.length == 10
0 <= mapping[i] <= 9
All the values of mapping[i] are unique.
1 <= nums.length <= 3 * 104
0 <= nums[i] < 109
Accepted
90,908
Submissions
158,080
*/

//Solutions
class Solution {
public:
    
    int search(int digi,unordered_map<int,int>mp){
        for(auto it:mp){
            if(it.second==digi){
                return it.first;
            }
        }
        return -1;
    }
    
    int helper(int dig,unordered_map<int,int>&mp){
        int ans=0;
        while(dig){
            int digi=dig%10;
            int a=search(digi,mp);
            ans=ans*10+a;
            dig=dig/10;
        }
        
        int anss=0;
        while(ans){
            int dig=ans%10;
            anss=anss*10+dig;
            ans=ans/10;
        }
        
        return anss;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(int i=0;i<mapping.size();i++){
            mp[mapping[i]]=i;
        }
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int dig=nums[i];
            int anss=helper(dig,mp);
            ans.push_back(anss);
        }
        
        multimap<int,int>mpp;
        for(int i=0;i<ans.size();i++){
            mpp.insert({ans[i],nums[i]});
        }
        
        
        vector<int>anss;
        for(auto it:mpp){
            anss.push_back(it.second);
        }
        return anss;
        
    }
};

//Not Accurate Gives error for 0 due to rotation (above code)

class Solution {
public:
    using int3=array<int, 3>;
    static int convert(int x, vector<int>& mapping){
        if (x==0) return mapping[0];//  edge case
        int z=0;
        for(int pow10=1; x>0; pow10*=10){
            auto [q, r]=div(x, 10);
            z+=mapping[r]*pow10;
            x=q;
        }
        return z;
    }

    static vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n=nums.size();
        vector<int3> mapNum(n);
        for(int i=0; i<n; i++){
            int x=nums[i];
            mapNum[i]={convert(x, mapping),i,  x};//(mapping nums, idx, x)
        }
        sort(mapNum.begin(), mapNum.end());// Use default sort is better
        for(int i=0; i<n; i++)
            nums[i]=mapNum[i][2];
        return nums;
    }
};

