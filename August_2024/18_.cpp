//264. Ugly Number II
/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
Accepted
408,744
Submissions
853,028
*/

//Solutions
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        
        int i2=0,i3=0,i5=0;
        int next2=2;
        int next3=3;
        int next5=5;
        
        for(int i=1;i<n;i++){
            int nextmin=min(next2,min(next3,next5));
            dp[i]=nextmin;
            
            if(nextmin==next2){
                i2++;
                next2=dp[i2]*2;
            }
            
            if(nextmin==next3){
                i3++;
                next3=dp[i3]*3;
            }
            if(nextmin==next5){
                i5++;
                next5=dp[i5]*5;
            }
            
        }
        return dp[n-1];
    }
};