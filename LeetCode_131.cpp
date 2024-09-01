/*
    131. Palindrome Partitioning

    Given a string s, partition s such that every substring of the partition is a 
    palindrome. Return all possible palindrome partitioning of s.

    Example 1:

    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
*/

// Solution: 

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, s, ans, path);
        return ans;
    }

    void solve(int index, string s, vector<vector<string>>& ans, vector<string>& path) {
        if(index == s.size()) {
            ans.push_back(path);
            return ;
        }

        for(int i = index ; i < s.size() ; i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, ans, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};