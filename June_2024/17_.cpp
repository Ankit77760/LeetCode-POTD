//633. Sum of Square Numbers
/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 231 - 1
*/

//Solutions
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++){
            long long j=sqrt(c-(i*i));
            if(((i*i)+(j*j))==c){
                return true;
            }
        }
        return false;
    }
};