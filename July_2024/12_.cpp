//1717. Maximum Score From Removing Substrings
/*
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.
Accepted
77,412
Submissions
130,185
*/

//Solutions
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res=0;
        string top,bot;
        int top_score,bot_score;
        
        if(x>y){
            top="ab";
            top_score=x;
            bot="ba";
            bot_score=y;
        }
        else{
            top="ba";
            top_score=y;
            bot="ab";
            bot_score=x;
        }
        
        vector<char>st1;
        for(char c:s){
            if(c==top[1] && !st1.empty() && st1.back()==top[0]){
                res+=top_score;
                st1.pop_back();
            }
            else{
                st1.push_back(c);
            }
        }
        
        
        vector<char>st2;
        for(char c:st1){
            if(c==bot[1] && !st2.empty() && st2.back()==bot[0]){
                res+=bot_score;
                st2.pop_back();
            }
            else{
                st2.push_back(c);
            }
        }
        return res;
    }
};