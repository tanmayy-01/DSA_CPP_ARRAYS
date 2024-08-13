/*
    39. Combination Sum

    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
    frequency of at least one of the chosen numbers is different.
*/

// Solution: Recursion

class Solution {
public:

    void findCombination(int index, int target, vector<int>& arr, vector<vector<int>>&ans, vector<int>& ds) {
        if(index == arr.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return ;
        }

        if(arr[index] <= target) {
            ds.push_back(arr[index]);
            findCombination(index, target - arr[index], arr, ans, ds);
            ds.pop_back();
        }

        findCombination(index + 1, target, arr, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target, candidates, ans, ds);
        return ans;
        
    }
};
