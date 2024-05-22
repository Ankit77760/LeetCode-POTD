//131. Palindrome Partitioning
/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.*/

//Solutions
class Solution {
public:

    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void helper(string &s,int index,vector<vector<string>>&ans,vector<string>&curr){
        if(s.size()==index){
            ans.push_back(curr);
            return ;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));
                helper(s, i + 1, ans, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>current;
        helper(s,0,ans,current);
        return ans;
    }
};