//1002. Find Common Characters
/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/

//Solutions
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> commonFreq(26, INT_MAX);  
        
        for (const string& w : words) {
            vector<int> charFreq(26, 0);
            for (char c : w) {
                charFreq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                commonFreq[i] = min(commonFreq[i], charFreq[i]);
            }
        }
        
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (commonFreq[i] > 0) {
                result.push_back(string(1, i + 'a'));
                commonFreq[i]--;
            }
        }
        
        return result;
    }
};