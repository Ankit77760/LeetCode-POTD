//912. Sort an Array
/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
Accepted
724,815
Submissions
1,258,450
*/

//Solutions
class Solution {
public:
    
    void merge(vector<int>&nums,int start,int mid,int end){
        int n1=mid-start+1;
        int n2=end-mid;
        
        vector<int>num1(n1);
        vector<int>num2(n2);
        
        for(int i=0;i<n1;i++){
            num1[i]=nums[i+start];
        }
        for(int i=0;i<n2;i++){
            num2[i]=nums[mid+1+i];
        }
        
        int i=0,j=0,k=start;
        while(i<n1 && j<n2){
            if(num1[i] < num2[j]){
                nums[k]=num1[i];
                i++;
            }
            else{
                nums[k]=num2[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k]=num1[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=num2[j];
            j++;
            k++;
        }
        
        
    }
    
    void mergeSort(vector<int>&nums,int start,int end){
        if(start<end){
        
        int mid=(start+end)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        
        merge(nums,start,mid,end);
        }
        }
    
    vector<int> sortArray(vector<int>& nums) {
        if(!nums.empty()){
            mergeSort(nums,0,nums.size()-1);
        }
        return nums;
    }
};